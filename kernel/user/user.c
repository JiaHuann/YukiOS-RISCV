#include <kernel/os.h>

#define DELAY 100

void user_task0(void)
{
	uart_puts("Task 0: Created!\n");
	reg_t ret = -1;
	ret = get_sstatus(&ret);
	printf("sstatus is %d",ret);
	while (1)
	{
		uart_puts("Task 0: Running...\n");

		task_delay(DELAY);
	}
}

void user_task1(void)
{
	while (1)
	{
		uart_puts("Task 1: Running...\n");
		task_delay(DELAY);
		// task_yield();
	}
}

/* NOTICE: DON'T LOOP INFINITELY IN main() */
void os_main(void)
{
	task_create(user_task0);
	task_create(user_task1);
}
