#include "kernel/syscall.h"
.global get_sstatus
# 规范：a7-->系统调用号 a0~a5-->参数 a0-->返回值
get_sstatus:
    li a7, SYSCALL_get_sstatus
    ecall
    ret