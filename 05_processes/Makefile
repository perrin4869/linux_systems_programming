CC=gcc

# Should be equivalent to your list of C files, if you don't build selectively
SRC=$(wildcard *.c)
OUT=$(SRC:%.c=%)

all: $(OUT)

$(OUT):
	$(CC) -o $@ $@.c

.PHONY: all clean

clean:
	rm -rf $(OUT)
