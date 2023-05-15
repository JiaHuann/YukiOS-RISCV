#include <kernel/types.h>
#include <kernel/os.h>

extern void uart_init(void);
extern void uart_puts(char *s);
extern void sched_init(void);
extern void schedule(void);


volatile int main_counter = 1000;

static inline void init_hard(uint_64 hart_id)
{
    asm volatile("mv tp, %0"
                 :
                 : "r"(hart_id & 0x7));
}



// void init_sched(){
//     //设置栈指针
//     ctx_task.sp = (reg_t)&task_stack[STACK_SIZE - 1]; 
//     //设置任务的第一条指令地址（函数名本身就是地址）
//     ctx_task.ra = (reg_t)user_task0;

// }


void start_kernel(uint_64 hart_id)
{
    init_hard(hart_id);
    // uart_init();
	// uart_puts("Hello, My first OS!\n");
    sched_init();
    schedule();

   
}