$(CFLAGS) += -I$(ROOT_DIR)/include

objs := entry.o init.o

.PHONY: build clean

build: $(objs)

%.o: %.S
	$(GCC) $(CFLAGS) -c $<

%.o: %.c
	$(GCC) $(CFLAGS) -c $<

clean:
	rm -rf $(RMDOT)


include ../../basic.mk
