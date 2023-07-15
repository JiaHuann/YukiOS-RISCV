.macro reg_save base //接受一个base作为参数
	sd ra, 0(\base)
	sd sp, 8(\base)
	sd gp, 16(\base)
	sd tp, 24(\base)
	sd t0, 32(\base)
	sd t1, 40(\base)
	sd t2, 48(\base)
	sd s0, 56(\base)
	sd s1, 64(\base)
	sd a0, 72(\base)
	sd a1, 80(\base)
	sd a2, 88(\base)
	sd a3, 96(\base)
	sd a4, 104(\base)
	sd a5, 112(\base)
	sd a6, 120(\base)
	sd a7, 128(\base)
	sd s2, 136(\base)
	sd s3, 144(\base)
	sd s4, 152(\base)
	sd s5, 160(\base)
	sd s6, 168(\base)
	sd s7, 176(\base)
	sd s8, 184(\base)
	sd s9, 192(\base)
	sd s10, 200(\base)
	sd s11, 208(\base)
	sd t3, 216(\base)
	sd t4, 224(\base)
	sd t5, 232(\base)
    # 暂时不保存t6，还在使用，我们在switch中手动保存。
.endm

# 恢复上下文 传入t6
.macro reg_restore base
	ld ra, 0(\base)
	ld sp, 8(\base)
	ld gp, 16(\base)
	ld tp, 24(\base)
	ld t0, 32(\base)
	ld t1, 40(\base)
	ld t2, 48(\base)
	ld s0, 56(\base)
	ld s1, 64(\base)
	ld a0, 72(\base)
	ld a1, 80(\base)
	ld a2, 88(\base)
	ld a3, 96(\base)
	ld a4, 104(\base)
	ld a5, 112(\base)
	ld a6, 120(\base)
	ld a7, 128(\base)
	ld s2, 136(\base)
	ld s3, 144(\base)
	ld s4, 152(\base)
	ld s5, 160(\base)
	ld s6, 168(\base)
	ld s7, 176(\base)
	ld s8, 184(\base)
	ld s9, 192(\base)
	ld s10, 200(\base)
	ld s11, 208(\base)
	ld t3, 216(\base)
	ld t4, 224(\base)
	ld t5, 232(\base)
	ld t6, 240(\base)
.endm


.text
# 调用swich_to; 下一个context的栈指针在 a0里(caller args register)

.global switch_to
.align 4
switch_to:
    # 1.保存上下文
	csrrw	t6, sscratch, t6	//sscratch指向当前运行上下文，
                                //这里我们用t6寄存器来保存sscratch指向的当前上下文地址。
	beqz	t6, 1f	//初始化后第一次调用sscratch寄存器的值是0，无法保存现场

	reg_save t6			// 保存现场context

	# 2.单独保存t6（因为我们使用t6指向上下文，被使用过程中似乎无法保存？）
	mv	t5, t6		
	// csrr	t6, sscratch	// 重新读取  其实没必要
	sw	t6, 240(t5)	

1: //跳过保存
	# 3.sscratch指向新的上下文结构地址
	csrw	sscratch, a0  

	mv	t6, a0    #t6指向新的上下文结构地址

    # 4.恢复要切换的上下文结构中的所有寄存器
	reg_restore t6

	# Do actual context switching.
	ret


.global trap_vector
.align 4
trap_vector:
	# 1.保存上下文
	csrrw t6, sscratch, t6 //读取当前上下文结构体地址到t6
	reg_save t6 //保存运行流当前上下文
	csrw sscratch, t6//恢复sscratch的值

	# 2.调用C写的处理函数
	csrr a0, sepc	//传入sret后返回到的指令的地址
	csrr a1, scause	//传入异常类型
	call trap_handler//调用处理函数

	# 3.根据需要可能在trap_handle结束后修改sepc的跳转（通过a0传返回值）
	csrw sepc, a0

	# 4.恢复上下文 返回
	csrr t6, sscratch
	reg_restore t6

	sret


.end
