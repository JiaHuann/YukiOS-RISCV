#include "general/poison.h"
#include <kernel/types.h>
#include <sbi.h>

void console_init() {
}

inline void putchar(char chr) {
        register unit_64 a0 asm ("a0") = (unit_64) chr;
        register unit_64 a7 asm ("a7") = (unit_64) SBI_CONSOLE_PUTCHAR;
        asm volatile ("ecall" : "+r" (a0) : "r" (a7) : "memory");
}
