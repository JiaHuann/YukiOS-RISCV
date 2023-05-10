#ifndef _MFOS_TYPES_H
#define _MFOS_TYPES_H
// DO NOT includ this file dicrtly
#ifdef KERNEL_TYPE_H
#undef offsetof 
#define offsetof(TYPE, MEMBER) __builtin_offsetof(TYPE, MEMBER)

// size of a struct field in bytes
#define sizeof_field(TYPE, MEMBER) sizeof((((TYPE *)0)->MEMBER))

// offset of a struct field within the struct
#define offsettoend(TYPE, MEMBER) \
        (offsetof(TYPE, MEMBER) + sizeof_field(TYPE, MEMBER))

#define NULL ((void *)0)

typedef int_8 bool;
enum {
        false,
        true 
};
//posix types

#undef __FD_SETSIZE
#define __FD_SETSIZE 1024

typedef struct { 
        unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
} __kernel_fd_set;

struct list_head {
        struct list_head *next, *prev;
};
#endif


#endif
