
all: src/langton.c src/langton.h src/matrix.c src/matrix.h
	$(CC) -c src/langton.c

clean:
	rm -fr *.o

.PHONY: clean
