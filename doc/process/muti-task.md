# 协作式多任务

**`FuncPATH`:** 
- kernel/sched/co-sched.o   
- kernel/boot/user.c   

**`TypePATH`:** 
- include/kernel/os.h

# 0x01 Type

## static int _top
创建的任务个数

## static int _current
当前任务
## #define MAX_TASKS 10      
最大任务数量
## #define STACK_SIZE 1024
栈大小
## typedef void (*taskFunc_ptr)(void);
最naive的函数指针

# 0x02 Function

## void sched_init(void);
初始化调度

## void schedule(void);
主动放弃CPU并通过简单的`膜总任务数量`进行轮转到下一个任务并切换上下文

## void task_yield()
包装schedule，目前无太大区别。

## int task_create(taskFunc_ptr new_task)
>args：
1. 传入一个目标任务函数指针。

>ret：
- -1：任务达到最大数量
- 0：创建成功


## void os_main(void);
创建两个示例task。

# 0x03 生命周期
```
start_kernel--->sched_init--->os_main/task_create--->schdule/task_yield  <--------------|
                                                            |                           | 
                                                           \|/                          |
                                                        switch_to--->任务${_current}----->
```
# 0x04 注意
1. 内核init后先进行sched_init,第一次创建任务后必须`手动调用schedule`或task_yield，以从`任务0:start_kernel`（_current=-1）进入到任务1。
2. 由于是协作式多任务，任务本身必须在最后调用schedule或`task_yield`


