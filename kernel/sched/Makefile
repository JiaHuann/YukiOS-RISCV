# INCL = ../../include

objs := co_sched.o

.PHONY: build clean

build: $(objs)

%.o: %.S
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(RMDOT)


include ../../basic.mk
