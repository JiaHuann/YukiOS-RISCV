# 上下文切换(Macro)

`void switch_to(struct context *next)`

## 0x00 逻辑
保存当前context（`struct context`），恢复next指向的context。利用`sscratch（CSR）`来保存和切换。



## 0x01 实现细节
- sscratch(CSR),t6(TEMP Register),a0(args Register)

**非系统第一次调用:**

`t6`通过`sscratch`指向当前上下文，保存`t6`指向的`当前context struct现场`，再额外保存t6。`sscratch`设置指向下一个上下文`a0`（`struct context *next`），`t6`指向`a0`，恢复`t6`指向的下一个`context struct`，结束。

**系统第一次调用：**

省去保护现场。

## 0x02 fix bug :
**注意！！**：qemu+opensbi启动后所有内容都运行在S-mode下,所以使用的是sscratch而非mscratch，详见riscv的spec。
