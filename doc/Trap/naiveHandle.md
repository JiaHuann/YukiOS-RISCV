# 简单异常/中断处理（Base addr+分支处理）

**`TypePATH`:** 
- include/kernel/riscv.h


**`FuncPATH`:**
- kernel/interrupt/trap.c
- kernel/boot/context.S

# 0x01 Type

# 0x02 Function

## void trap_init()
初始化Trap，并写入stvec寄存器trap入口函数的基地址trap_vector,trap_vector是一段汇编，执行调用trap_handler的逻辑。



## reg_t trap_handler(reg_t epc, reg_t cause)
Trap处理程序（内部区分中断/异常）
>args:
1. sepc寄存器（异常处理完后sret返回地址）
2. scause寄存器（Trap原因+中断/异常号）

>ret:
1.trap结束后的返回地址，根据需要如果要跳到进入trap的下一条指令就需要+4（32bit）

# 0x03 ASM

## trap_vector
触发trap的入口点，控制进入trap处理函数的逻辑。保存trap前上下文并在trap处理程序运行结束后恢复上下文，恢复特权级，继续执行下一条指令/触发trap的指令。

>目前是无论哪种trap都进入指定的一个处理程序，然后通过switch来处理不同code的trap/exception，效率较低。
（如果要修改Base addr为Vectored方式则在此修改逻辑，调用指定offset的中断处理函数）

# 0x04 生命周期
```
kernel_start--->trap_init(base/vectored)--->********---->触发Trap----->trap_vector---->trap_handler
                                                  /|\                                     |
                                                   |                                      |
                                                   |--------------------------------------|
                                                            下一条指令/触发trap的指令
```

# 待办

- [ ] 修改`指定base addr处理程序+switch` 为 `vectored+多处理程序`(hint：看stvec寄存器)