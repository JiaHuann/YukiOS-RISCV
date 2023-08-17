# INCL = ../../include

objs := printf.o console.o uart.o 

.PHONY: build clean

build: $(objs)

%.o: %.S
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(RMDOT)


include ../../basic.mk
