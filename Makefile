SRCS = $(wildcard c/*.c)
PROGS = $(patsubst %.c,%.out,$(SRCS))

.PHONY: all
all: $(PROGS)

%.out: %.c
	gcc -Wall -Wextra -o $@ $<

.PHONY: run
run: $(PROGS)
	for out in c/*.out; do echo "\nTask $$out:"; $$out; echo "\n"; done

.PHONY: clean
clean:
	rm -f $(PROGS)