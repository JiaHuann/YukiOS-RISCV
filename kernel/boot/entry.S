#include <mem_config.h>

    .section .boot
    .globl _start
_start:
    mv t0, a0
    add t0, t0, 1
    slli t0, t0, 16
    la sp, kernel_stack
    add sp, sp, t0
    call start_kernel

loop:
    j loop

    .section .stack
    .globl kernel_stack
    .align 12
kernel_stack:
    .space KERNEL_STACK_SIZE * 5
    .globl kernel_stack_top
kernel_stack_top:

    .section .pgdir
    .align 12
    .globl kernel_page_directory
kernel_page_directory:
    .space PAGE_SIZE
