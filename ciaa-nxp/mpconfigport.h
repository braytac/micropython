#include <stdint.h>

// options to control how Micro Python is built

#define MICROPY_QSTR_BYTES_IN_HASH  (1)
#define MICROPY_ALLOC_PATH_MAX      (512)
#define MICROPY_EMIT_X64            (0)
#define MICROPY_EMIT_THUMB          (1)
#define MICROPY_EMIT_INLINE_THUMB   (1)
#define MICROPY_COMP_MODULE_CONST   (1)
#define MICROPY_COMP_CONST          (1)
#define MICROPY_COMP_DOUBLE_TUPLE_ASSIGN (1)
#define MICROPY_COMP_TRIPLE_TUPLE_ASSIGN (1)
#define MICROPY_MEM_STATS           (0)
#define MICROPY_DEBUG_PRINTERS      (0)
#define MICROPY_ENABLE_GC           (1)
#define MICROPY_HELPER_REPL         (1)
#define MICROPY_HELPER_LEXER_UNIX   (0)
#define MICROPY_ENABLE_SOURCE_LINE  (1)
#define MICROPY_ENABLE_DOC_STRING   (1)
#define MICROPY_ERROR_REPORTING     (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_BUILTIN_METHOD_CHECK_SELF_ARG (0)

#define MICROPY_PY_BUILTINS_BYTEARRAY      (1)
#define MICROPY_PY_BUILTINS_MEMORYVIEW     (1)
#define MICROPY_PY_BUILTINS_ENUMERATE      (1)
#define MICROPY_PY_BUILTINS_FROZENSET      (1)
#define MICROPY_PY_BUILTINS_REVERSED       (1)
#define MICROPY_PY_BUILTINS_SET            (1)
#define MICROPY_PY_BUILTINS_SLICE          (1)
#define MICROPY_PY_BUILTINS_PROPERTY       (1)
#define MICROPY_PY_FUNCTION_ATTRS          (1)
#define MICROPY_PY_BUILTINS_STR_UNICODE    (1)
#define MICROPY_PY_BUILTINS_STR_SPLITLINES (1)
#define MICROPY_PY_BUILTINS_EXECFILE       (1)

#define MICROPY_PY___FILE__         (0)
#define MICROPY_PY_GC               (1)
#define MICROPY_PY_ARRAY            (1)
#define MICROPY_PY_ATTRTUPLE        (1)
#define MICROPY_PY_COLLECTIONS      (1)
#define MICROPY_PY_MATH             (1)
#define MICROPY_PY_CMATH            (1)
#define MICROPY_PY_IO               (1)
#define MICROPY_PY_STRUCT           (1)
#define MICROPY_PY_SYS              (1)
#define MICROPY_CPYTHON_COMPAT      (0)
#define MICROPY_LONGINT_IMPL        (MICROPY_LONGINT_IMPL_NONE)
#define MICROPY_FLOAT_IMPL          (MICROPY_FLOAT_IMPL_FLOAT)

#define MICROPY_PY_IO_FILEIO        (0)
#define MICROPY_PY_UBINASCII        (1)
#define MICROPY_PY_UCTYPES          (1)
#define MICROPY_PY_UZLIB            (1)
#define MICROPY_PY_UJSON            (1)
#define MICROPY_PY_URE              (1)
#define MICROPY_PY_UHEAPQ           (1)
#define MICROPY_PY_UHASHLIB         (1)

// Optimizations
#define MICROPY_OPT_COMPUTED_GOTO (0)
#define MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE (0)


// type definitions for the specific machine

#define BYTES_PER_WORD (4)

#define MICROPY_MAKE_POINTER_CALLABLE(p) ((void*)((mp_uint_t)(p) | 1))

#define UINT_FMT "%lu"
#define INT_FMT "%ld"

typedef int32_t mp_int_t; // must be pointer size
typedef uint32_t mp_uint_t; // must be pointer size
typedef void *machine_ptr_t; // must be of pointer size
typedef const void *machine_const_ptr_t; // must be of pointer size
typedef long mp_off_t;

// extra built in names to add to the global namespace
extern const struct _mp_obj_fun_builtin_t mp_builtin_open_obj;
#define MICROPY_PORT_BUILTINS \
    { MP_OBJ_NEW_QSTR(MP_QSTR_open), (mp_obj_t)&mp_builtin_open_obj },

// extra builtin modules to add to the list of known ones
extern const struct _mp_obj_module_t pyb_module;
extern const struct _mp_obj_module_t mp_module_collections;
extern const struct _mp_obj_module_t mp_module_ustruct;
extern const struct _mp_obj_module_t mp_module_ubinascii;
extern const struct _mp_obj_module_t mp_module_ure;
extern const struct _mp_obj_module_t mp_module_uzlib;
extern const struct _mp_obj_module_t mp_module_ujson;
extern const struct _mp_obj_module_t mp_module_uheapq;
extern const struct _mp_obj_module_t mp_module_uhashlib;
extern const struct _mp_obj_module_t mp_module_uos;
extern const struct _mp_obj_module_t mp_module_utime;

#define MICROPY_PORT_BUILTIN_MODULES \
    { MP_OBJ_NEW_QSTR(MP_QSTR_pyb), (mp_obj_t)&pyb_module }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_collections), (mp_obj_t)&mp_module_collections }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_struct), (mp_obj_t)&mp_module_ustruct }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_binascii), (mp_obj_t)&mp_module_ubinascii }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_re), (mp_obj_t)&mp_module_ure }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_zlib), (mp_obj_t)&mp_module_uzlib }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_json), (mp_obj_t)&mp_module_ujson }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_heapq), (mp_obj_t)&mp_module_uheapq }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_hashlib), (mp_obj_t)&mp_module_uhashlib }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_uos), (mp_obj_t)&mp_module_uos }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_os), (mp_obj_t)&mp_module_uos }, \


// We need to provide a declaration/definition of alloca()
#include <alloca.h>

// We need to provide a declaration/definition of alloca()
//#define alloca(x) (void*)m_new(byte, (x))

//static inline void mp_hal_set_interrupt_char(char c) {}

#define MICROPY_HW_BOARD_NAME "EDU-CIAA-NXP"
#define MICROPY_HW_MCU_NAME "LPC4337"

#define MP_STATE_PORT MP_STATE_VM

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8];

#define MICROPY_HAL_H "ciaanxp_mphal.h"