SRCS = $(wildcard c/*.c)
PROGS = $(patsubst %.c,%.out,$(SRCS))

.PHONY: all
all: $(PROGS)

%: %.c
	gcc -Wall -Wextra -o $@.out $<

.PHONY: clean
clean:
	rm -f $(PROGS)