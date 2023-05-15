#ifndef KERNEL_TYPE_H
#define KERNEL_TYPE_H

typedef unsigned __attribute__((__mode__(QI))) uint_8;
typedef unsigned __attribute__((__mode__(HI))) uint_16;
typedef unsigned __attribute__((__mode__(SI))) uint_32;
typedef unsigned __attribute__((__mode__(DI))) uint_64;
typedef int __attribute__((__mode__(QI))) int_8;
typedef int __attribute__((__mode__(HI))) int_16;
typedef int __attribute__((__mode__(SI))) int_32;
typedef int __attribute__((__mode__(DI))) int_64;

typedef uint_32 reg_t;

typedef __builtin_va_list va_list;
#define va_start(ap, param) __builtin_va_start(ap, param)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap, type) __builtin_va_arg(ap, type)

#include <general/types.h>

#endif

