#include <kernel/types.h>
#include <kernel/riscv.h>

typedef void (*taskFunc_ptr)(void);


/* uart */
extern void uart_init();
extern int uart_putc(char ch);
extern void uart_puts(char *s);

/* muti-tasks */
extern int  task_create(taskFunc_ptr);
extern void task_delay(volatile int count);
extern void task_yield();

extern void sched_init(void);
extern void schedule(void);
extern void os_main(void);

/* Trap */
extern void trap_init();
extern void trap_test();



struct context { //上下文寄存器
	/* ignore x0 */
	reg_t ra;
	reg_t sp;
	reg_t gp;
	reg_t tp;
	reg_t t0;
	reg_t t1;
	reg_t t2;
	reg_t s0;
	reg_t s1;
	reg_t a0;
	reg_t a1;
	reg_t a2;
	reg_t a3;
	reg_t a4;
	reg_t a5;
	reg_t a6;
	reg_t a7;
	reg_t s2;
	reg_t s3;
	reg_t s4;
	reg_t s5;
	reg_t s6;
	reg_t s7;
	reg_t s8;
	reg_t s9;
	reg_t s10;
	reg_t s11;
	reg_t t3;
	reg_t t4;
	reg_t t5;
	reg_t t6;
};