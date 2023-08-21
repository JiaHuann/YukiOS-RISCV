#include <kernel/os.h>

volatile int main_counter = 1000;

static inline void init_hard(uint64_t hart_id)
{
    asm volatile("mv tp, %0"
                 :
                 : "r"(hart_id & 0x7));
}

void start_kernel(uint64_t hart_id)
{
    init_hard(hart_id);
    uart_puts("[init] HART init\n");
    task_delay(5000);
    uart_init();
    task_delay(5000);
    trap_init();
    task_delay(5000);
    timer_init();
    task_delay(5000);
    sched_init();
    task_delay(5000);
    uart_puts("[init] Virtual Page Memory init\n");
    task_delay(5000);
    os_main();
    task_delay(10000);
    uart_puts("Hello, My first OS!\n");
    task_delay(5000);
    printf("[start] schdule starting!\n");
    schedule();
    uart_puts("Would not go here!\n");
}