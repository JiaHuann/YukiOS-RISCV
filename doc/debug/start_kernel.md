# qemu启动进入内核调试

进入 `根目录` 运行 `make debug`
如果环境没问题可以触发

```gdb
Breakpoint 1, _entry () at entry.S:6
6           mv t0, a0
=> 0x0000000080200000 <_entry+0>:       93 02 05 00     mv      t0,a0
```
```gdb
Breakpoint 2, start_kernel (hart_id=0) at init.c:12
12          init_hard(hart_id);
```

## 测试自己的模块

1. 更改Makefile构建就行，从debug标识符开始两行删除然后改掉。
2. 然后改掉qemu和gdb的`-kernel $(BOOT_DIR)/$(VMLINUX)` 和`$(BOOT_DIR)/$(VMLINUX)`设置为你生成的img文件目录就行。

位置`$(git rev-parse --show-toplevel)/Makefile`

## gdbinit配置文件
位置：`$(git rev-parse --show-toplevel)/gdbinit`

配置进入gdb调试`默认`运行的指令

可以设置断点,port,也可以根据需求打印寄存器等等，自行配置，配置好了记得完善文档



---
## 注意：
退出gdb先kill在quit，不然端口释放不掉。
## 代办

- [ ] 完善GDB调试配置文件
- [ ] 生成正式内核去掉CFLAGS中 -g选项