#ifndef _MFOS_POISON_H
#define _MFOS_POISON_H

#define POISON_POINTER 0xdead000000000000

#define LIST_POISON_P ((void *) 0x111 + POISON_POINTER)
#define LIST_POISON_N ((void *) 0x222 + POISON_POINTER)

#endif

