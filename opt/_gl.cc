#include <GL/gl.h>


#include "ext/Module.h"
#include "ext/Type.h"
#include "ext/Func.h"

extern "C"
void crack_ext__gl_init(crack::ext::Module *mod) {
    crack::ext::Func *f;
    crack::ext::Type *type_Class = mod->getClassType();

    crack::ext::Type *array = mod->getType("array");
    crack::ext::Type *type_byte = mod->getByteType();

    crack::ext::Type *array_pbyte_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_byte;
        array_pbyte_q = array->getSpecialization(params);
    }
    crack::ext::Type *type_float32 = mod->getFloat32Type();

    crack::ext::Type *array_pfloat32_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_float32;
        array_pfloat32_q = array->getSpecialization(params);
    }
    crack::ext::Type *type_float64 = mod->getFloat64Type();

    crack::ext::Type *array_pfloat64_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_float64;
        array_pfloat64_q = array->getSpecialization(params);
    }
    crack::ext::Type *type_int = mod->getIntType();

    crack::ext::Type *array_pint_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_int;
        array_pint_q = array->getSpecialization(params);
    }
    crack::ext::Type *type_uint = mod->getUintType();

    crack::ext::Type *array_puint_q;
    {
        std::vector<crack::ext::Type *> params(1);
        params[0] = type_uint;
        array_puint_q = array->getSpecialization(params);
    }
    crack::ext::Type *type_bool = mod->getBoolType();
    crack::ext::Type *type_byteptr = mod->getByteptrType();
    crack::ext::Type *type_float = mod->getFloatType();
    crack::ext::Type *type_int32 = mod->getInt32Type();
    crack::ext::Type *type_int64 = mod->getInt64Type();
    crack::ext::Type *type_uint32 = mod->getUint32Type();
    crack::ext::Type *type_uint64 = mod->getUint64Type();
    crack::ext::Type *type_void = mod->getVoidType();
    crack::ext::Type *type_voidptr = mod->getVoidptrType();

    f = mod->addFunc(type_void, "glMatrixMode",
                     (void *)glMatrixMode
                     );
    f->addArg(type_uint, "mode");

    f = mod->addFunc(type_void, "glLoadIdentity",
                     (void *)glLoadIdentity
                     );

    f = mod->addFunc(type_void, "glFrustum",
                     (void *)glFrustum
                     );
    f->addArg(type_float64, "left");
    f->addArg(type_float64, "right");
    f->addArg(type_float64, "bottom");
    f->addArg(type_float64, "top");
    f->addArg(type_float64, "nearVal");
    f->addArg(type_float64, "farVal");

    f = mod->addFunc(type_void, "glFlush",
                     (void *)glFlush
                     );

    f = mod->addFunc(type_void, "glMultMatrixd",
                     (void *)glMultMatrixd
                     );
    f->addArg(type_float64, "matrix");

    f = mod->addFunc(type_void, "glMultMatrixf",
                     (void *)glMultMatrixf
                     );
    f->addArg(type_float32, "matrix");

    f = mod->addFunc(type_void, "glTranslated",
                     (void *)glTranslated
                     );
    f->addArg(type_float64, "x");
    f->addArg(type_float64, "y");
    f->addArg(type_float64, "z");

    f = mod->addFunc(type_void, "glTranslatef",
                     (void *)glTranslatef
                     );
    f->addArg(type_float32, "x");
    f->addArg(type_float32, "y");
    f->addArg(type_float32, "z");

    f = mod->addFunc(type_void, "glBegin",
                     (void *)glBegin
                     );
    f->addArg(type_uint, "mode");

    f = mod->addFunc(type_void, "glEnd",
                     (void *)glEnd
                     );

    f = mod->addFunc(type_void, "glVertex2d",
                     (void *)glVertex2d
                     );
    f->addArg(type_float64, "x");
    f->addArg(type_float64, "y");

    f = mod->addFunc(type_void, "glVertex2f",
                     (void *)glVertex2f
                     );
    f->addArg(type_float32, "x");
    f->addArg(type_float32, "y");

    f = mod->addFunc(type_void, "glVertex2i",
                     (void *)glVertex2i
                     );
    f->addArg(type_int, "x");
    f->addArg(type_int, "y");

    f = mod->addFunc(type_void, "glVertex3d",
                     (void *)glVertex3d
                     );
    f->addArg(type_float64, "x");
    f->addArg(type_float64, "y");
    f->addArg(type_float64, "z");

    f = mod->addFunc(type_void, "glVertex3f",
                     (void *)glVertex3f
                     );
    f->addArg(type_float32, "x");
    f->addArg(type_float32, "y");
    f->addArg(type_float32, "z");

    f = mod->addFunc(type_void, "glVertex3i",
                     (void *)glVertex3i
                     );
    f->addArg(type_int, "x");
    f->addArg(type_int, "y");
    f->addArg(type_int, "z");

    f = mod->addFunc(type_void, "glVertex4d",
                     (void *)glVertex4d
                     );
    f->addArg(type_float64, "x");
    f->addArg(type_float64, "y");
    f->addArg(type_float64, "z");
    f->addArg(type_float64, "w");

    f = mod->addFunc(type_void, "glVertex4f",
                     (void *)glVertex4f
                     );
    f->addArg(type_float32, "x");
    f->addArg(type_float32, "y");
    f->addArg(type_float32, "z");
    f->addArg(type_float32, "w");

    f = mod->addFunc(type_void, "glVertex4i",
                     (void *)glVertex4i
                     );
    f->addArg(type_int, "x");
    f->addArg(type_int, "y");
    f->addArg(type_int, "z");
    f->addArg(type_int, "w");

    f = mod->addFunc(type_void, "glVertex2dv",
                     (void *)glVertex2dv
                     );
    f->addArg(array_pfloat64_q, "v");

    f = mod->addFunc(type_void, "glVertex2fv",
                     (void *)glVertex2fv
                     );
    f->addArg(array_pfloat32_q, "v");

    f = mod->addFunc(type_void, "glVertex2iv",
                     (void *)glVertex2iv
                     );
    f->addArg(array_pint_q, "v");

    f = mod->addFunc(type_void, "glVertex3dv",
                     (void *)glVertex3dv
                     );
    f->addArg(array_pfloat64_q, "v");

    f = mod->addFunc(type_void, "glVertex3fv",
                     (void *)glVertex3fv
                     );
    f->addArg(array_pfloat32_q, "v");

    f = mod->addFunc(type_void, "glVertex3iv",
                     (void *)glVertex3iv
                     );
    f->addArg(array_pint_q, "v");

    f = mod->addFunc(type_void, "glVertex4dv",
                     (void *)glVertex4dv
                     );
    f->addArg(array_pfloat64_q, "v");

    f = mod->addFunc(type_void, "glVertex4fv",
                     (void *)glVertex4fv
                     );
    f->addArg(array_pfloat32_q, "v");

    f = mod->addFunc(type_void, "glVertex4iv",
                     (void *)glVertex4iv
                     );
    f->addArg(array_pint_q, "v");

    f = mod->addFunc(type_void, "glColor3b",
                     (void *)glColor3b
                     );
    f->addArg(type_byte, "red");
    f->addArg(type_byte, "green");
    f->addArg(type_byte, "blue");

    f = mod->addFunc(type_void, "glColor3d",
                     (void *)glColor3d
                     );
    f->addArg(type_float64, "red");
    f->addArg(type_float64, "green");
    f->addArg(type_float64, "blue");

    f = mod->addFunc(type_void, "glColor3f",
                     (void *)glColor3f
                     );
    f->addArg(type_float32, "red");
    f->addArg(type_float32, "green");
    f->addArg(type_float32, "blue");

    f = mod->addFunc(type_void, "glColor3i",
                     (void *)glColor3i
                     );
    f->addArg(type_int, "red");
    f->addArg(type_int, "green");
    f->addArg(type_int, "blue");

    f = mod->addFunc(type_void, "glColor3ui",
                     (void *)glColor3ui
                     );
    f->addArg(type_uint, "red");
    f->addArg(type_uint, "green");
    f->addArg(type_uint, "blue");

    f = mod->addFunc(type_void, "glColor4b",
                     (void *)glColor4b
                     );
    f->addArg(type_byte, "red");
    f->addArg(type_byte, "green");
    f->addArg(type_byte, "blue");
    f->addArg(type_byte, "alpha");

    f = mod->addFunc(type_void, "glColor4d",
                     (void *)glColor4d
                     );
    f->addArg(type_float64, "red");
    f->addArg(type_float64, "green");
    f->addArg(type_float64, "blue");
    f->addArg(type_float64, "alpha");

    f = mod->addFunc(type_void, "glColor4f",
                     (void *)glColor4f
                     );
    f->addArg(type_float32, "red");
    f->addArg(type_float32, "green");
    f->addArg(type_float32, "blue");
    f->addArg(type_float32, "alpha");

    f = mod->addFunc(type_void, "glColor4i",
                     (void *)glColor4i
                     );
    f->addArg(type_int, "red");
    f->addArg(type_int, "green");
    f->addArg(type_int, "blue");
    f->addArg(type_int, "alpha");

    f = mod->addFunc(type_void, "glColor4ui",
                     (void *)glColor4ui
                     );
    f->addArg(type_uint, "red");
    f->addArg(type_uint, "green");
    f->addArg(type_uint, "blue");
    f->addArg(type_uint, "alpha");

    f = mod->addFunc(type_void, "glColor3bv",
                     (void *)glColor3bv
                     );
    f->addArg(array_pbyte_q, "v");

    f = mod->addFunc(type_void, "glColor3dv",
                     (void *)glColor3dv
                     );
    f->addArg(array_pfloat64_q, "v");

    f = mod->addFunc(type_void, "glColor3fv",
                     (void *)glColor3fv
                     );
    f->addArg(array_pfloat32_q, "v");

    f = mod->addFunc(type_void, "glColor3iv",
                     (void *)glColor3iv
                     );
    f->addArg(array_pint_q, "v");

    f = mod->addFunc(type_void, "glColor3uiv",
                     (void *)glColor3uiv
                     );
    f->addArg(array_puint_q, "v");

    f = mod->addFunc(type_void, "glColor4bv",
                     (void *)glColor4bv
                     );
    f->addArg(array_pbyte_q, "v");

    f = mod->addFunc(type_void, "glColor4dv",
                     (void *)glColor4dv
                     );
    f->addArg(array_pfloat64_q, "v");

    f = mod->addFunc(type_void, "glColor4fv",
                     (void *)glColor4fv
                     );
    f->addArg(array_pfloat32_q, "v");

    f = mod->addFunc(type_void, "glColor4iv",
                     (void *)glColor4iv
                     );
    f->addArg(array_pint_q, "v");

    f = mod->addFunc(type_void, "glColor4uiv",
                     (void *)glColor4uiv
                     );
    f->addArg(array_puint_q, "v");

    f = mod->addFunc(type_void, "glViewport",
                     (void *)glViewport
                     );
    f->addArg(type_int, "x");
    f->addArg(type_int, "y");
    f->addArg(type_int, "width");
    f->addArg(type_int, "height");

    f = mod->addFunc(type_void, "glClearColor",
                     (void *)glClearColor
                     );
    f->addArg(type_float32, "red");
    f->addArg(type_float32, "green");
    f->addArg(type_float32, "blue");
    f->addArg(type_float32, "alpha");

    f = mod->addFunc(type_void, "glClearDepth",
                     (void *)glClearDepth
                     );
    f->addArg(type_float32, "depth");

    f = mod->addFunc(type_void, "glClear",
                     (void *)glClear
                     );
    f->addArg(type_uint, "mask");

    f = mod->addFunc(type_void, "glShadeModel",
                     (void *)glShadeModel
                     );
    f->addArg(type_uint, "mode");

    f = mod->addFunc(type_void, "glPolygonMode",
                     (void *)glPolygonMode
                     );
    f->addArg(type_uint, "face");
    f->addArg(type_uint, "mode");

    f = mod->addFunc(type_void, "glEnable",
                     (void *)glEnable
                     );
    f->addArg(type_uint, "cap");

    f = mod->addFunc(type_void, "glDisable",
                     (void *)glDisable
                     );
    f->addArg(type_uint, "cap");

    f = mod->addFunc(type_void, "glDepthFunc",
                     (void *)glDepthFunc
                     );
    f->addArg(type_uint, "func");

    f = mod->addFunc(type_void, "glHint",
                     (void *)glHint
                     );
    f->addArg(type_uint, "target");
    f->addArg(type_uint, "mode");

    mod->addConstant(type_uint, "GL_PROJECTION",
                     static_cast<int>(GL_PROJECTION)
                     );

    mod->addConstant(type_uint, "GL_MODELVIEW",
                     static_cast<int>(GL_MODELVIEW)
                     );

    mod->addConstant(type_uint, "GL_POINTS",
                     static_cast<int>(GL_POINTS)
                     );

    mod->addConstant(type_uint, "GL_LINES",
                     static_cast<int>(GL_LINES)
                     );

    mod->addConstant(type_uint, "GL_LINE_LOOP",
                     static_cast<int>(GL_LINE_LOOP)
                     );

    mod->addConstant(type_uint, "GL_LINE_STRIP",
                     static_cast<int>(GL_LINE_STRIP)
                     );

    mod->addConstant(type_uint, "GL_TRIANGLES",
                     static_cast<int>(GL_TRIANGLES)
                     );

    mod->addConstant(type_uint, "GL_TRIANGLE_STRIP",
                     static_cast<int>(GL_TRIANGLE_STRIP)
                     );

    mod->addConstant(type_uint, "GL_TRIANGLE_FAN",
                     static_cast<int>(GL_TRIANGLE_FAN)
                     );

    mod->addConstant(type_uint, "GL_QUADS",
                     static_cast<int>(GL_QUADS)
                     );

    mod->addConstant(type_uint, "GL_QUAD_STRIP",
                     static_cast<int>(GL_QUAD_STRIP)
                     );

    mod->addConstant(type_uint, "GL_POLYGON",
                     static_cast<int>(GL_POLYGON)
                     );

    mod->addConstant(type_uint, "GL_CURRENT_BIT",
                     static_cast<int>(GL_CURRENT_BIT)
                     );

    mod->addConstant(type_uint, "GL_POINT_BIT",
                     static_cast<int>(GL_POINT_BIT)
                     );

    mod->addConstant(type_uint, "GL_LINE_BIT",
                     static_cast<int>(GL_LINE_BIT)
                     );

    mod->addConstant(type_uint, "GL_POLYGON_BIT",
                     static_cast<int>(GL_POLYGON_BIT)
                     );

    mod->addConstant(type_uint, "GL_POLYGON_STIPPLE_BIT",
                     static_cast<int>(GL_POLYGON_STIPPLE_BIT)
                     );

    mod->addConstant(type_uint, "GL_PIXEL_MODE_BIT",
                     static_cast<int>(GL_PIXEL_MODE_BIT)
                     );

    mod->addConstant(type_uint, "GL_LIGHTING_BIT",
                     static_cast<int>(GL_LIGHTING_BIT)
                     );

    mod->addConstant(type_uint, "GL_FOG_BIT",
                     static_cast<int>(GL_FOG_BIT)
                     );

    mod->addConstant(type_uint, "GL_DEPTH_BUFFER_BIT",
                     static_cast<int>(GL_DEPTH_BUFFER_BIT)
                     );

    mod->addConstant(type_uint, "GL_ACCUM_BUFFER_BIT",
                     static_cast<int>(GL_ACCUM_BUFFER_BIT)
                     );

    mod->addConstant(type_uint, "GL_STENCIL_BUFFER_BIT",
                     static_cast<int>(GL_STENCIL_BUFFER_BIT)
                     );

    mod->addConstant(type_uint, "GL_VIEWPORT_BIT",
                     static_cast<int>(GL_VIEWPORT_BIT)
                     );

    mod->addConstant(type_uint, "GL_TRANSFORM_BIT",
                     static_cast<int>(GL_TRANSFORM_BIT)
                     );

    mod->addConstant(type_uint, "GL_ENABLE_BIT",
                     static_cast<int>(GL_ENABLE_BIT)
                     );

    mod->addConstant(type_uint, "GL_COLOR_BUFFER_BIT",
                     static_cast<int>(GL_COLOR_BUFFER_BIT)
                     );

    mod->addConstant(type_uint, "GL_HINT_BIT",
                     static_cast<int>(GL_HINT_BIT)
                     );

    mod->addConstant(type_uint, "GL_EVAL_BIT",
                     static_cast<int>(GL_EVAL_BIT)
                     );

    mod->addConstant(type_uint, "GL_LIST_BIT",
                     static_cast<int>(GL_LIST_BIT)
                     );

    mod->addConstant(type_uint, "GL_TEXTURE_BIT",
                     static_cast<int>(GL_TEXTURE_BIT)
                     );

    mod->addConstant(type_uint, "GL_SCISSOR_BIT",
                     static_cast<int>(GL_SCISSOR_BIT)
                     );

    mod->addConstant(type_uint, "GL_ALL_ATTRIB_BITS",
                     static_cast<int>(GL_ALL_ATTRIB_BITS)
                     );

    mod->addConstant(type_uint, "GL_FILL",
                     static_cast<int>(GL_FILL)
                     );

    mod->addConstant(type_uint, "GL_SMOOTH",
                     static_cast<int>(GL_SMOOTH)
                     );

    mod->addConstant(type_uint, "GL_FRONT_AND_BACK",
                     static_cast<int>(GL_FRONT_AND_BACK)
                     );

    mod->addConstant(type_uint, "GL_DEPTH_TEST",
                     static_cast<int>(GL_DEPTH_TEST)
                     );

    mod->addConstant(type_uint, "GL_TEXTURE_2D",
                     static_cast<int>(GL_TEXTURE_2D)
                     );

    mod->addConstant(type_uint, "GL_LIGHTING",
                     static_cast<int>(GL_LIGHTING)
                     );

    mod->addConstant(type_uint, "GL_LEQUAL",
                     static_cast<int>(GL_LEQUAL)
                     );

    mod->addConstant(type_uint, "GL_PERSPECTIVE_CORRECTION_HINT",
                     static_cast<int>(GL_PERSPECTIVE_CORRECTION_HINT)
                     );

    mod->addConstant(type_uint, "GL_POINT_SMOOTH_HINT",
                     static_cast<int>(GL_POINT_SMOOTH_HINT)
                     );

    mod->addConstant(type_uint, "GL_LINE_SMOOTH_HINT",
                     static_cast<int>(GL_LINE_SMOOTH_HINT)
                     );

    mod->addConstant(type_uint, "GL_POLYGON_SMOOTH_HINT",
                     static_cast<int>(GL_POLYGON_SMOOTH_HINT)
                     );

    mod->addConstant(type_uint, "GL_FOG_HINT",
                     static_cast<int>(GL_FOG_HINT)
                     );

    mod->addConstant(type_uint, "GL_DONT_CARE",
                     static_cast<int>(GL_DONT_CARE)
                     );

    mod->addConstant(type_uint, "GL_FASTEST",
                     static_cast<int>(GL_FASTEST)
                     );

    mod->addConstant(type_uint, "GL_NICEST",
                     static_cast<int>(GL_NICEST)
                     );
}
