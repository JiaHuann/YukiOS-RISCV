#include "general/poison.h"
#include <kernel/types.h>
#include <sbi.h>

void console_init()
{
}

inline void putchar(char chr)
{
        register uint64_t a0 asm("a0") = (uint64_t)chr;
        register uint64_t a7 asm("a7") = (uint64_t)SBI_CONSOLE_PUTCHAR;
        asm volatile("ecall"
                     : "+r"(a0)
                     : "r"(a7)
                     : "memory");
}
