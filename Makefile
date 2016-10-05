
all: src/langton.c src/langton.h
	$(CC) -c src/langton.c -I deps/matrix

clean:
	rm -fr *.o

.PHONY: clean
