KERNEL	:= kernel
USER	:= user
BOOT_DIR = $(KERNEL)/boot
VMLINUX	:= vmlinux.img
LINKS	:= scripts/vmlinux.ld

ROOT_DIR := $(shell realpath .)

export $(ROOT_DIR)
OBJS := $(KERNEL)/*/*.o

debug: $(KERNEL)

	$(LD) $(LDFLAGS) -T $(LINKS) -o $(VMLINUX) $(OBJS)
	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel $(VMLINUX) -s -S &
	@${GDB} $(VMLINUX) -q -x ./gdbinit

.PHONY: .FORCE
$(KERNEL): .FORCE
	$(MAKE) build -C $@

%.o : %.c
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	for dir in $(KERNEL); do \
		$(MAKE) -C $$dir clean; \
	done;\
	rm -rf *.o *.img


include basic.mk



