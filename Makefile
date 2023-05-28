SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
all: $(PROGS)
%: %.c
    gcc -Wall -Wextra -o $@ $<
	./$@
clean:
    rm -f $(PROGS)