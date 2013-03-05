// Copyright 2009-2012 Google Inc.
// Copyright 2010 Shannon Weyrick <weyrick@mozek.us>
//
//   This Source Code Form is subject to the terms of the Mozilla Public
//   License, v. 2.0. If a copy of the MPL was not distributed with this
//   file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "VarDef.h"

#include "builder/Builder.h"
#include "spug/check.h"
#include "AssignExpr.h"
#include "Deserializer.h"
#include "VarDefImpl.h"
#include "Context.h"
#include "Expr.h"
#include "ModuleDefMap.h"
#include "ResultExpr.h"
#include "Serializer.h"
#include "TypeDef.h"

using namespace std;
using namespace model;

VarDef::VarDef(TypeDef *type, const std::string &name) :
    type(type),
    name(name),
    owner(0),
    constant(false) {
}

VarDef::~VarDef() {}

ResultExprPtr VarDef::emitAssignment(Context &context, Expr *expr) {
    AssignExprPtr assign = new AssignExpr(0, this, expr);
    return impl->emitAssignment(context, assign.get());
}

bool VarDef::hasInstSlot() {
    return impl->hasInstSlot();
}

int VarDef::getInstSlot() const {
    return impl->getInstSlot();
}

bool VarDef::isStatic() const {
    return false;
}

std::string VarDef::getFullName() const {
    if (!fullName.empty())
        return fullName;
    if (owner && !owner->getNamespaceName().empty())
        fullName = owner->getNamespaceName()+"."+name;
    else
        fullName = name;
    return fullName;
}

std::string VarDef::getDisplayName() const {
    assert(owner && "no owner defined when getting display name");
    std::string module = owner->getNamespaceName();
    if (!module.compare(0, 6, ".main.")) {
        // find the next namespace after the main script
        size_t pos = module.find('.', 6);
        if (pos != string::npos)
            return module.substr(pos + 1) + "." + name;
        else
            return name;
    } else if (module == ".builtin") {
        return name;
    } else {
        return getFullName();
    }
}

bool VarDef::isConstant() {
    return constant;
}

void VarDef::dump(ostream &out, const string &prefix) const {
    out << prefix << (type ? type->getFullName() : string("<null>")) << " " << name << endl;
}

void VarDef::dump() const {
    dump(std::cerr, "");
}

ModuleDef *VarDef::getModule() const {
    return owner->getModule().get();
}

bool VarDef::isSerializable(const Namespace *ns) const {
    return name[0] != ':' && owner == ns;
}

void VarDef::addDependenciesTo(ModuleDef *mod, VarDef::Set &added) const {

    ModuleDefPtr depMod = getModule();
    mod->addDependency(depMod.get());

    // add the dependencies of the type
    if (type.get() != this)
        type->addDependenciesTo(mod, added);
}

void VarDef::serializeExternCommon(Serializer &serializer,
                                   const TypeDef::TypeVec *localDeps
                                   ) const {
    serializer.write(getModule()->getFullName(), "module");
    serializer.write(name, "name");

    if (localDeps) {
        // write the list we've accumulated.
        serializer.write(localDeps->size(), "#localDeps");
        for (TypeDef::TypeVec::const_iterator iter = localDeps->begin();
            iter != localDeps->end();
            ++iter
            )
            (*iter)->serialize(serializer, false, 0);
    } else {
        serializer.write(0, "#localDeps");
    }
}

void VarDef::serializeExternRef(Serializer &serializer,
                                const TypeDef::TypeVec *localDeps
                                ) const {
    if (serializer.writeObject(this, "ext"))
        serializeExternCommon(serializer, localDeps);
}

void VarDef::serializeExtern(Serializer &serializer) const {
    serializeExternCommon(serializer, 0);
}

void VarDef::serializeAlias(Serializer &serializer, const string &alias) const {
    serializer.write(Serializer::aliasId, "kind");
    serializer.write(alias, "alias");
    serializeExtern(serializer);
}

namespace {

    TypeDef::TypeVecObjPtr parseTypeParameters(Context &context,
                                               string typeName,
                                               int parmStart
                                               );

    VarDefPtr resolveName(Context &context, const string &moduleName,
                           const string &symbolName
                           ) {
        // do a special check for array and function generics
        if (moduleName == ".builtin") {
            TypeDefPtr specialType;
            int parmStart;
            if (!symbolName.compare(0, 6, "array[")) {
                specialType = context.construct->arrayType;
                parmStart = 6;
            } else if (!symbolName.compare(0, 9, "function[")) {
                specialType = context.construct->functionType;
                parmStart = 9;
            }

            if (specialType) {
                return specialType->getSpecialization(
                    context,
                    parseTypeParameters(context, symbolName, parmStart).get()
                );
            }
        }

        ModuleDefPtr module = context.construct->getModule(moduleName);
        SPUG_CHECK(module,
                   "Unable to find module " << moduleName <<
                    " which contains referenced symbol " << symbolName
                   );
        VarDefPtr var = module->lookUp(symbolName);
        SPUG_CHECK(var,
                   "Unable to find symbol " << moduleName << "." <<
                    symbolName
                   );
        return var;
    }

    TypeDefPtr resolveType(Context &context, string fullTypeName) {
        // find the end of the module name
        int lastPeriod = -1;
        for (int i = 0; i < fullTypeName.size() && fullTypeName[i] != '[';
             ++i
             ) {
            if (fullTypeName[i] == '.')
                lastPeriod = i;
        }

        SPUG_CHECK(lastPeriod > 0,
                   "no module name found in type name: " << fullTypeName
                   );
        return resolveName(context, fullTypeName.substr(0, lastPeriod),
                           fullTypeName.substr(lastPeriod + 1)
                           );
    }

    TypeDef::TypeVecObjPtr parseTypeParameters(Context &context,
                                               string name,
                                               int parmStart
                                               ) {
        TypeDef::TypeVecObjPtr parms = new TypeDef::TypeVecObj;
        int i = parmStart;
        while (name[i] != ']') {
            int start = i;
            for (; name[i] != ']' && name[i] != ','; ++i);
            parms->push_back(resolveType(context, name.substr(start, i - start)));
            if (name[i] == ',')
                ++i;
        }
        return parms;
    }

} // anon namespace

VarDefPtr VarDef::deserializeAliasBody(Deserializer &deser) {
    string moduleName = deser.readString(Serializer::modNameSize,
                                         "module"
                                         );
    string name = deser.readString(Serializer::varNameSize, "name");

    // deserialize the local dependencies
    int depCount = deser.readUInt("#localDeps");
    for (int i = 0; i < depCount; ++i)
        TypeDef::deserialize(deser);

    return resolveName(*deser.context, moduleName, name);
}

namespace {
    struct AliasReader : public Deserializer::ObjectReader {
        virtual spug::RCBasePtr read(Deserializer &deser) const {
            return VarDef::deserializeAliasBody(deser);
        }
    };
}

VarDefPtr VarDef::deserializeAlias(Deserializer &serializer) {
    return VarDefPtr::rcast(serializer.readObject(AliasReader(),
                                                  "ext"
                                                  ).object
                            );
}

void VarDef::serialize(Serializer &serializer, bool writeKind,
                       const Namespace *ns
                       ) const {
    if (writeKind)
        serializer.write(Serializer::variableId, "kind");
    serializer.write(name, "name");
    serializer.write(getInstSlot() + 1, "instSlot");
    type->serialize(serializer, false, ns);
}

VarDefPtr VarDef::deserialize(Deserializer &deser) {
    string name = deser.readString(16, "name");
    int instSlot = static_cast<int>(deser.readUInt("instSlot")) - 1;
    TypeDefPtr type = TypeDef::deserialize(deser);
    return deser.context->builder.materializeVar(*deser.context, name,
                                                 type.get(),
                                                 instSlot
                                                 );
}