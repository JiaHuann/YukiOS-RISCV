KERNEL	:= kernel
USER	:= user
BOOT_DIR = $(KERNEL)/boot
VMLINUX	:= vmlinux.img
LINKS	:= scripts/vmlinux.ld

ROOT_DIR := $(shell realpath .)

export $(ROOT_DIR)

.PYONY: build clean

OBJS = $(KERNEL)/*/*.o

build: $(KERNEL)
	$(LD) $(LDFLAGS) -T $(LINKS) -o $(vmlinux) $(OBJS)

$(KERNEL):
	$(MAKE) build -C $@

clean:
	for dir in $(KERNEL), $(USER); do \
		$(MAKE) -C $$dir clean; \
	done;\
	rm -rf *.o *.img



debug:
	make -C $(BOOT_DIR)
	$(LD) $(LDFLAGS) -T $(LINKS) -o ./kernel/boot/$(VMLINUX) ./kernel/boot/*.o


	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel $(BOOT_DIR)/$(VMLINUX) -s -S &
	@${GDB} $(BOOT_DIR)/$(VMLINUX) -q -x ./gdbinit


include basic.mk



