compiler = gcc
debug: test
all:test
	./test 
test: main.o draw.o check_white_or_black.o input_output.o knight_move.o bishop_moves.o rook_move.o queen_move.o miscellaneous.o undo.o
	$(compiler) main.o draw.o check_white_or_black.o input_output.o knight_move.o bishop_moves.o rook_move.o queen_move.o miscellaneous.o undo.o -o test -g
main.o: main.c header.h
	$(compiler) -c main.c -g
draw.o: draw.c header.h
	$(compiler) -c draw.c -g
check_white_or_black.o: check_white_or_black.c header.h
	$(compiler) -c check_white_or_black.c -g
input_output.o: input_output.c header.h
	$(compiler) -c input_output.c -g
knight_move.o: knight_move.c header.h
	$(compiler) -c knight_move.c -g
bishop_moves.o: bishop_moves.c header.h
	$(compiler) -c bishop_moves.c -g
rook_move.o: rook_move.c header.h
	$(compiler) -c rook_move.c -g
queen_move.o: queen_move.c header.h
	$(compiler) -c queen_move.c -g
miscellaneous.o: header.h
	$(compiler) -c miscellaneous.c -g
undo.o: header.h
	$(compiler) -c undo.c -g
clean:
	rm -f *.o test