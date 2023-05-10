#include <kernel/types.h>
#include <sbi.h>

volatile int main_counter = 1000;

static inline void init_hard(unit_64 hart_id) {
    asm volatile("mv tp, %0" : : "r" (hart_id & 0x7));
}


void start_kernel(unit_64 hart_id) {
    init_hard(hart_id);

    if (main_counter == 1000) {
        extern unit_64 bssst[];
        extern unit_64 bsse[];
        for (unit_64 *i = bsss; i < bsse; i++) {
            *i = 0;
        }
        main_counter = main_counter + 1;

        console_init();
        pageLock_init();
        printf("Hello, risc-v!\nBoot hart_id: %ld \n\n", hart_id);

        memory_init();
        process_init();


        for (int i = 1; i < 5; ++ i) {
            if (i != hart_id) {
                unsigned long mask = 1 << i;
                setMode(i);
                sbi_send_ipi(&mask);
            }
        }

        trap_init();


    }
}
