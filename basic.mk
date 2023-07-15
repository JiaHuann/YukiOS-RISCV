TOOLPRE	:= riscv64-unknown-elf-
CC	:= $(TOOLPRE)gcc
AS	:= $(TOOLPRE)gas
LD	:= $(TOOLPRE)ld
OBJCOPY	:= $(TOOLPRE)objcopy
OBJDUMP := $(TOOLPRE)objdump


CFLAGS	:= -Wall -Werror -O -fomit-frame-pointer
DEBUG_FLAGS	:= -g -ggdb -gdwarf-2
CFLAGS	+= -MD
CFLAGS 	+= -mcmodel=medany -mno-relax -march=rv64g -mabi=lp64f
CFLAGS 	+= -I.
CFLAGS 	+= -nostdlib -fno-stack-protector

LDFLAGS	:= -z max-page-size=4096

QEMU	:= qemu-system-riscv64

RMDOT	:= "*.o *.d *~"
