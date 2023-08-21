TOOLPRE	:= riscv64-unknown-elf-
CC	:= $(TOOLPRE)gcc
AS	:= $(TOOLPRE)gas
LD	:= $(TOOLPRE)ld
OBJCOPY	:= $(TOOLPRE)objcopy
OBJDUMP := $(TOOLPRE)objdump

#先默认加上-g 最后生成时再去掉
CFLAGS	:= -Werror -O -fomit-frame-pointer -g -Wno-error=unused-variable

CFLAGS	+= -MD
CFLAGS 	+= -mcmodel=medany -mno-relax -march=rv64g -mabi=lp64f
CFLAGS 	+= -I../../include
CFLAGS 	+= -nostdlib -fno-stack-protector -fno-builtin

LDFLAGS	:= -z max-page-size=4096

QEMU	:= qemu-system-riscv64
QFLAGS := -machine virt -m 128M -nographic -bios default \
		# -drive file=disk.img,if=none,format=raw,id=x0 \
		# -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0
GDB = gdb-multiarch

RMDOT	:= *.o *.d *~
