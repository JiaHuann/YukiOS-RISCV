#ifndef KERNEL_TYPE_H
#define KERNEL_TYPE_H

typedef unsigned __attribute__((__mode__(QI))) unit_8;
typedef unsigned __attribute__((__mode__(HI))) unit_16;
typedef unsigned __attribute__((__mode__(SI))) unit_32;
typedef unsigned __attribute__((__mode__(DI))) unit_64;
typedef int __attribute__((__mode__(QI))) int_8;
typedef int __attribute__((__mode__(HI))) int_16;
typedef int __attribute__((__mode__(SI))) int_32;
typedef int __attribute__((__mode__(DI))) int_64;


typedef __builtin_va_list va_list;
#define va_start(ap, param) __builtin_va_start(ap, param)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap, type) __builtin_va_arg(ap, type)

#include <general/types.h>

#endif

