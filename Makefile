compiler = gcc
debug: test
all:test
	./test 
test: main.o draw.o check_white_or_black.o input_output.o knight_move.o bishop_moves.o rook_move.o queen_move.o undo.o miscellaneous.o file.o passant.o paw_move.o
	$(compiler) main.o draw.o check_white_or_black.o input_output.o knight_move.o bishop_moves.o rook_move.o queen_move.o undo.o miscellaneous.o file.o  passant.o paw_move.o -o test -g
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
passant.o: passant.c header.h
	$(compiler) -c passant.c -g
paw_move.o: paw_move.c header.h
	$(compiler) -c paw_move.c -g
undo.o: undo.c header.h
	$(compiler) -c undo.c -g
miscellaneous.o: miscellaneous.o header.h
	$(compiler) -c miscellaneous.c -g
file.o: file.o header.h
	$(compiler) -c file.c -g
clean:
	rm -f *.o test