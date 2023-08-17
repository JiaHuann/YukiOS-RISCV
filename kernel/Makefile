
SUBSYSDIR := $(shell ls -d */)

.PHONY: build clean $(SUBSYSDIR)

build: $(SUBSYSDIR)

$(SUBSYSDIR):
	$(MAKE) build -C $@

clean:
	for dir in $(SUBSYSDIR); do \
		$(MAKE) -C $$dir clean; \
	done;\
	rm -rf *.o *~

include ../basic.mk
