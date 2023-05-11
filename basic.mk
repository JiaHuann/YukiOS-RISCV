TOOLPRE	:= riscv64-unknown-elf-
CC	:= $(TOOLPRE)gcc
AS	:= $(TOOLPRE)gas
LD	:= $(TOOLPRE)ld
OBJCOPY	:= $(TOOLPRE)objcopy
OBJDUMP := $(TOOLPRE)objdump

#先默认加上-g 最后生成时再去掉
CFLAGS	:= -Wall -Werror -O -fomit-frame-pointer -g

CFLAGS	+= -MD
CFLAGS 	+= -mcmodel=medany -mno-relax -march=rv64g -mabi=lp64f
CFLAGS 	+= -I.
CFLAGS 	+= -nostdlib -fno-stack-protector

LDFLAGS	:= -z max-page-size=4096

QEMU	:= qemu-system-riscv64
QFLAGS := -machine virt -m 128M -nographic -bios default

GDB = gdb-multiarch

RMDOT	:= *.o *.d *~
