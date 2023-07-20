# 宏
## define CLINT 0x02000000L
定义局部（内部）中断CLINT寄存器映射的地址
qemu-virt借鉴SFIVE设置
[virt.c](https://github.com/qemu/qemu/blob/master/hw/riscv/virt.c)

## define TIMER_INTERVAL CLINT_TIMEBASE_FREQ / HZ
定义TIMER_INTERVAl为一秒的时间间隔

# 结构体
## struct timer 定时器实例
>/include/kernel/os.h

- `void (*func)(void *arg)` 为定时器绑定callback函数
- `void *arg` 标记该timer是否被使用
- `uint32_t timeout_tick` 设置超时tick数

# 函数
## timer_init() 初始化timer模块
>/kernel/boot/timer.c

调用timer_load并w_sie打开定时器中断

## timer_load(uint64_t) 设置下一次中断间隔
> /kernel/boot/timer.c

~~关于timer这里RISCV定义的也很不明确，挺混乱的，可能是我还没太看懂吧。~~

利用SBI的模拟CSR读取（不是CLINT的MIMO的mtime)[riscv\_encoding.h](https://github.com/riscv-software-src/opensbi/blob/6b5188ca14e59ce7bf71afe4e7d3d557c3d31bf8/include/sbi/riscv_encoding.h#L247)是Unprivileged and User-Level CSR 供SBI使用

发生ecall 0号调用，调用opensbi封装好的SBI_SET_TIMER
[sbi\_ecall\_interface.h](https://github.com/riscv-software-src/opensbi/blob/master/include/sbi/sbi_ecall_interface.h)

## timer_check() 更新所有timer
>/kernel/boot/timer.c


## timer_handler() 定时器中断异常处理
>/kernel/boot/timer.c



# 生命周期
```c
start_kernel---->timer_init
						|- timer_load
									|-ecall 0号
						|- w_sie 开启定时器中断

CLINT中断到来
		|---->trap_vector
						|--->trap_vector
									|
									|--->trap_handler
												|
												|--->timer_handler
																|
																|-timer_check
																|-timer_load重新设置间隔
									
```