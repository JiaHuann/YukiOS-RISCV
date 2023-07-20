#ifndef __RISCV_H__
#define __RISCV_H__

#include <kernel/types.h>

#define SIE_SEIE (1 << 9) // external
#define SIE_STIE (1 << 5)  // timer
#define SIE_SSIE (1 << 1)  // software

#define SIP_SEIP (1 << 9) // external
#define SIP_STIP (1 << 5)  // timer
#define SIP_SSIP (1 << 1)  // software


#define SSTATUS_SIE (1 << 1)


static inline reg_t r_sstatus()
{
	reg_t x;
	asm volatile("csrr %0, sstatus" : "=r" (x) );
	return x;
}

static inline void w_sstatus(reg_t x)
{
	asm volatile("csrw sstatus, %0" : : "r" (x));
}


static inline reg_t r_sepc()
{
	reg_t x;
	asm volatile("csrr %0, sepc" : "=r" (x));
	return x;
}

static inline void w_sepc(reg_t x)
{
	asm volatile("csrw sepc, %0" : : "r" (x));
}


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


static inline reg_t r_sie()
{
	reg_t x;
	asm volatile("csrr %0, sie" : "=r" (x) );
	return x;
}

static inline void w_sie(reg_t x)
{
	asm volatile("csrw sie, %0" : : "r" (x));
}

static inline reg_t r_sip()
{
	reg_t x;
	asm volatile("csrr %0, sip" : "=r" (x) );
	return x;
}

static inline void w_sip(reg_t x)
{
	asm volatile("csrw sip, %0" : : "r" (x));
}

static inline reg_t r_scause()
{
	reg_t x;
	asm volatile("csrr %0, scause" : "=r" (x) );
	return x;
}

static inline reg_t r_stval()
{
	reg_t x;
	asm volatile("csrr %0, stval" : "=r" (x) );
	return x;
}


// 此MTIME非CLINT的那个MMIO的MTIME, 是Unprivileged and User-Level CSR
// 供SBI使用
// 在https://github.com/riscv-software-src/opensbi/blob/v1.2/include/sbi/riscv_encoding.h#L247
// SBI版本更新可能会不在这一行
static inline reg_t r_mtime()
{
	reg_t x;
	asm volatile("csrr %0, 0x000C01" : "=r" (x) );
	return x;
}

#endif /* __RISCV_H__ */