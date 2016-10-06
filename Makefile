
all: src/langton.c src/langton.h matrix.o
	$(CC) -c src/langton.c matrix.o -Ideps/matrix

matrix.o:
	$(CC) -c deps/matrix/matrix.c

test: all
	$(CC) test.c langton.o matrix.o -o test -Isrc -Ideps/matrix
	./test

clean:
	rm -fr *.o ./test

.PHONY: clean
