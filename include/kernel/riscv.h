#ifndef __RISCV_H__
#define __RISCV_H__

#include <kernel/types.h>


//Smode写入 mtvec（Machine Trap-Vector Base-Address）
static inline void w_stvec(reg_t x){
    asm volatile("csrw stvec, %0" : : "r" (x));
}
 

static inline void w_sscratch(reg_t x)
{
    asm volatile("csrw sscratch, %0"
                 :
                 : "r"(x));
}


#endif /* __RISCV_H__ */