# 运行方法
> 前提：本地有gcc riscv交叉编译工具 以及qemu-system-riscv64
```shell
make debug
```
# todo

- [x] 链接脚本vmlinux.ld
- [x] 添加gdb-multiarch debug
- [x] uart初始化
- [x] schedule初始化，上下文切换
- [x] 简单协作式多任务
- [x] trap初始化，简单trap处理(中断+异常)
- [x] timer初始化简单硬件软件定时器
- [x] 简单定时器抢占调度
- [x] 简单系统调用
- [x] 简单分页虚拟内存 (Not Merged)
- [ ] 简单用户进程(`S-mode`->`U-mode`)
- [ ] virtio初始化,io初始化
- [ ] FAT文件系统移植
- [ ] VFS抽象层
- [ ] 二进制加载器
- [ ] 简单shell
- [ ] 添加更多系统调用

