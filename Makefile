compiler = clang
all:test
	./test > output.text
test: main.o draw.o
	$(compiler) main.o draw.o -o test
main.o: main.c header.h
	$(compiler) -c main.c
draw.o: draw.c header.h
	$(compiler) -c draw.c
clean:
	rm -f *.o test