CC=gcc

# Should be equivalent to your list of C files, if you don't build selectively
SRC=$(wildcard *.c)
OUT=$(SRC:%.c=%)

all: $(OUT)

$(OUT): $(SRC)
	$(CC) -o $@ $@.c

.PHONY: all clean

clean:
	rm -rf $(OUT) f1 f2 f3
