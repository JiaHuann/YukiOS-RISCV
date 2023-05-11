KERNEL	:= kernel
USER	:= user

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
	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel vmkernel.img -s -S &
	@${GDB} vmkernel.img -q -x ./gdbinit


include basic.mk



