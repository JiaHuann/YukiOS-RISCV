$(CFLAGS) += -I$(ROOT_DIR)/include

objs := console.o printf.o

.PHONY: build clean

build: $(objs)

%.o: %.S
	$(GCC) $(CFLAGS) -c $<

%.o: %.c
	$(GCC) $(CFLAGS) -c $<

clean:
	rm -rf $(RMDOT)


include ../../basic.mk
