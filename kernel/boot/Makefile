INCL = ../../include

objs := lock.o timer.o entry.o context.o ../interrupt/trap.o ../diver/uart.o ../sched/co_sched.o init.o user.o printf.o

.PHONY: build clean

build: $(objs)

%.o: %.S
	$(CC) $(CFLAGS) -I$(INCL)  -c $<

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCL)  -c $<

clean:
	rm -rf $(RMDOT)


include ../../basic.mk
