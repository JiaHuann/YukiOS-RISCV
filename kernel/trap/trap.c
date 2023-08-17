#include <kernel/os.h>

// extern void trap_vector(void);
// extern void timer_handler(void);
// extern void schedule(void);

void trap_init()
{
	/*在S-mode设置中断向量基地址 */
	w_stvec((reg_t)trap_vector);
}

reg_t trap_handler(reg_t epc, reg_t cause, struct context *ctx)
{
	reg_t return_pc = epc;
	reg_t cause_code = cause & 0xfff; // 获取cause.ExceptionCode

	reg_t interrupt_mask = 0x1; // 中断号掩码
	interrupt_mask = interrupt_mask << 63;

	if (cause & interrupt_mask)
	{ // 中断处理
		switch (cause_code)
		{
		case 1:
			uart_puts("software interruption!\n");
			/*
			 * acknowledge the software interrupt by clearing
			 * the MSIP bit in mip.
			 */
			// int id = r_mhartid();
			// 	*(uint32_t*)CLINT_MSIP(id) = 0;

			//	S态不能用这种方式触发SIP
			//	我们直接用写SIP的方式触发

			// 好像不能用，下次再测试吧。
			w_sip(r_sip() & ~SIP_SSIP);

			// schedule();

			break;
		case 3:
			uart_puts("machine software interruption!\n");
			break;
		case 5:
			uart_puts("timer interruption!\n");
			timer_handler();
			break;
		case 7:
			uart_puts("reserve!\n");
			break;
		case 11:
			uart_puts("external interruption!\n");
			break;
		default:
			uart_puts("unknown async exception!\n");
			break;
		}
	}
	else
	{ // 异常处理
		printf("Sync exceptions!, code = %ld\n", cause_code);
		switch (cause_code)
		{
			case 8:
				printf("Enviroment call from USER");
				do_syscall(ctx);
				//panic("stop");
				return_pc += 4; //sepc存放的是ecall指令本身地址，必须特殊处理
				break;

			default:
				panic("OMG :( panic!");
		}
	}

	return return_pc;
}

void trap_test() // 测试
{
	/*
	 * Synchronous exception code = 7
	 * Store/AMO access fault
	 */
	*(int *)0x00000000 = 100;

	/*
	 * Synchronous exception code = 5
	 * Load access fault
	 */
	// int a = *(int *)0x00000000;

	uart_puts("Yeah! I'm return back from trap!\n");
}