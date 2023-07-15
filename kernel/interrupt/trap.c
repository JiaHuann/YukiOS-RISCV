#include <kernel/os.h>

extern void trap_vector(void);

void trap_init(){
    /*在S-mode设置中断向量基地址 */
    w_stvec((reg_t)trap_vector);
}


reg_t trap_handler(reg_t epc, reg_t cause){
    reg_t return_pc = epc;
    reg_t cause_code = cause & 0xfff; //获取cause.ExceptionCode

    if(cause & 0x8000000000000000){//中断处理
        switch (cause_code) {
		case 3:
			uart_puts("software interruption!\n");
			break;
		case 7:
			uart_puts("timer interruption!\n");
			break;
		case 11:
			uart_puts("external interruption!\n");
			break;
		default:
			uart_puts("unknown async exception!\n");
			break;
		}
    }else{//异常处理
        uart_puts("Get into exception!\n");
    
    }

    return return_pc;
}


void trap_test()//测试
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
	//int a = *(int *)0x00000000;

	uart_puts("Yeah! I'm return back from trap!\n");
}