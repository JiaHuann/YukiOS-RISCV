
SUBSYSDIR := $(shell find . -mindepth 1 -maxdepth 1 -type d -not -name '.*' -exec basename {} \;)

.PHONY: build clean $(modules)

build: $(SUBSYSDIR)

$(SUBSYSDIR):
	$(MAKE) build -C $@

clean:
	for dir in $(SUBSYSDIR); do \
		$(MAKE) -C $$dir clean; \
	done;\
	rm -rf *.o *~

include ../basic.mk
