#include <kernel/os.h>

volatile int main_counter = 1000;

static inline void init_hard(uint_64 hart_id)
{
    asm volatile("mv tp, %0"
                 :
                 : "r"(hart_id & 0x7));
}

void start_kernel(uint_64 hart_id)
{
    init_hard(hart_id);
    uart_init();
    uart_puts("Hello, My first OS!\n");
    trap_init();
    sched_init();
    os_main();
    schedule();
    uart_puts("Would not go here!\n");
}