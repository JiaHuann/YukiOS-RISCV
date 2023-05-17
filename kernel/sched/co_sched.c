#include <kernel/os.h>


/* defined in entry.S */
extern void switch_to(struct context *next);


#define MAX_TASKS 10     // 最大任务数量
#define STACK_SIZE 1024 // 栈大小


uint_8 task_stack[MAX_TASKS][STACK_SIZE]; // 定义所有任务的栈空间
struct context ctx_tasks[MAX_TASKS];       // 定义所以TASK的上下文结构


static int _top = 0;      // 标识当前创建任务个数
static int _current = -1; // 标识当前任务上下文




void sched_init()
{
    w_sscratch(0);
}


void schedule()//简单膜轮转协作式调度
{
    if (_top <= 0)
    {
        uart_puts("No task has been created");
        return;
    }
    _current = (_current + 1) % _top; //轮转

    struct context *next = &(ctx_tasks[_current]); //获取current任务的上下文
    switch_to(next);
}


int task_create(taskFunc_ptr new_task){
	if (_top < MAX_TASKS) {
		ctx_tasks[_top].sp = (reg_t)&task_stack[_top][STACK_SIZE - 1];
		ctx_tasks[_top].ra = (reg_t)new_task;
		_top++;
		return 0;
	} else {
		return -1;
	}
}


/*
 * a very rough implementaion, just to consume the cpu
 */
void task_delay(volatile int count)
{
    count *= 50000;
    while (count--)
        ;
}


//主动放弃cpu
void task_yield()
{
	schedule();
}