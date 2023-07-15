#include "general/poison.h"
#include <kernel/types.h>
#include <sbi.h>

void console_init() {
}

inline void putchar(char chr) {
        register uint_64 a0 asm ("a0") = (uint_64) chr;
        register uint_64 a7 asm ("a7") = (uint_64) SBI_CONSOLE_PUTCHAR;
        asm volatile ("ecall" : "+r" (a0) : "r" (a7) : "memory");
}
