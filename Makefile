SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

.PHONY: all
all: $(PROGS)

%: %.c
	gcc -Wall -Wextra -o $@ $<

.PHONY: clean
clean:
	rm -f $(PROGS)