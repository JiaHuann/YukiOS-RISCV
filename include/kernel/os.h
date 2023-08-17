#ifndef __OS_H_
#define __OS_H_

#include "kernel/types.h"
#include "kernel/riscv.h"
#include <stddef.h>
#include <stdarg.h>
#include "kernel/platform.h"
#include "kernel/os_def.h"
#include "kernel/usyscall.h"
// #include "vdisk.h"

typedef void (*taskFunc_ptr)(void);

/* uart */
extern void uart_init();
extern int uart_putc(char ch);
extern void uart_puts(char *s);

/* print*/
extern int printf(const char *s, ...);
extern void panic(char *s);

/* muti-tasks */
extern int task_create(taskFunc_ptr);
extern void task_delay(volatile int count);
extern void task_yield();

extern void sched_init(void);
extern void schedule(void);
extern void os_main(void);

/* Trap */
extern void trap_init();
extern void trap_test();

/*Lock*/
extern int spin_lock(void);
extern int spin_unlock(void);

extern void trap_vector(void);
extern void timer_handler(void);
extern void schedule(void);

/*syscall*/
extern void do_syscall(struct context *);

/*timer*/
struct timer
{
	void (*func)(void *arg);
	void *arg;
	uint32_t timeout_tick;
};

extern struct timer *timer_create(void (*handler)(void *arg), void *arg, uint32_t timeout);
extern void timer_delete(struct timer *timer);
extern void timer_init(void);

//driver




#endif