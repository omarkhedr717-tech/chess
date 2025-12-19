compiler = clang
all:test
	./test 
test: main.o draw.o check_white_or_black.o input_output.o knight_move.o bishop_moves.o rook_move.o queen_move.o paw_move.o
	$(compiler) main.o draw.o check_white_or_black.o input_output.o knight_move.o bishop_moves.o rook_move.o queen_move.o paw_move.o -o test
main.o: main.c header.h
	$(compiler) -c main.c
draw.o: draw.c header.h
	$(compiler) -c draw.c
check_white_or_black.o: check_white_or_black.c header.h
	$(compiler) -c check_white_or_black.c
input_output.o: input_output.c header.h
	$(compiler) -c input_output.c
knight_move.o: knight_move.c header.h
	$(compiler) -c knight_move.c
bishop_moves.o: bishop_moves.c header.h
	$(compiler) -c bishop_moves.c
rook_move.o: rook_move.c header.h
	$(compiler) -c rook_move.c
queen_move.o: queen_move.c header.h
	$(compiler) -c queen_move.c
paw_move.o:paw_move.c header.h
	$(compiler) -c paw_move.c
clean:
	rm -f *.o test