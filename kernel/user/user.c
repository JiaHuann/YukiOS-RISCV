#include <kernel/os.h>

#define DELAY 800

void user_task0(void)
{
	uart_puts("Task 0: Created!\n");
	printf("[init] syscall init success!\n");
	while (1)
	{
		uart_puts("Task 0: Running...\n");
		reg_t ret = -1;
		ret = get_sstatus(&ret);
		printf("[U-mode]sstatus is %x\n\n",ret);

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
	printf("[start] User Task created!\n");
	task_create(user_task0);
	task_create(user_task1);
}
