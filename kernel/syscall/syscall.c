#include "kernel/os.h"

reg_t __get_sstatus(reg_t* SYSCALL_id){
    printf("syscall--->get_sstatus arg0:0x%x\n",SYSCALL_id);
    reg_t content = r_sstatus();
    return content;
}


void do_syscall(struct context *ctx)
{
    reg_t SYSCALL_id = ctx->a7;
    switch (SYSCALL_id)
    {
        case 1: 
            //printf("before a0 :%x\n",ctx->a0);
            ctx->a0 = __get_sstatus((reg_t*)(ctx->a0));
            //printf("after a0 :%x",ctx->a0);
            break;
        default:
            printf("don't have this syscall id :%d", SYSCALL_id);
            panic("no SYSCALL id");
    }
    return;
}