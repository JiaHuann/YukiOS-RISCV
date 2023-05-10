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

include basic.mk



