compiler = gcc

debug: program
all: program
	./program
build:
	$(compiler) -g -c src/*.c
	mv *.o object/
program: build
	$(compiler) -g object/*.o -o program
clean:
	rm -rf object/*.o program