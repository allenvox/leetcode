DIRGUARD = @mkdir -p $(@D)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wsign-conversion
CSRC = $(wildcard src/c/*.c)
CEXEC = $(patsubst src/c/%.c,bin/%,$(CSRC))

CXX = g++
CXXFLAGS = -pedantic -std=c++17
CXXSRC = $(wildcard src/cpp/*.cpp)
CXXEXEC = $(patsubst src/cpp/%.cpp,bin/%,$(CXXSRC))

UNAME = $(uname)
ifeq ($(UNAME), Darwin)
CFLAGS += -ld_classic
endif

.PHONY: all
all: $(CEXEC) $(CXXEXEC)

bin/%: src/c/%.c
	$(DIRGUARD)
	$(CC) $(CFLAGS) -o $@ $<

bin/%: src/cpp/%.cpp
	$(DIRGUARD)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -o $@ $<

.PHONY: run
.SILENT: run
run: $(CEXEC) $(CXXEXEC)
	for out in bin/*; do echo "\nTask $$out:"; $$out; done

.PHONY: clean
.SILENT: clean
clean:
	rm -f $(CEXEC) $(CXXEXEC)

.PHONY: format
.SILENT: format
format:
	clang-format -i $(CSRC) $(CXXSRC)