INCL = ../../include

objs := entry.o init.o ../diver/uart.o

.PHONY: build clean

build: $(objs)

%.o: %.S
	$(CC) $(CFLAGS) -I$(INCL)  -c $<

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCL)  -c $<

clean:
	rm -rf $(RMDOT)


include ../../basic.mk
