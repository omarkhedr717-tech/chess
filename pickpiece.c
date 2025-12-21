#include "header.h"

void PickPiece(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[15][32],char kill_black[15][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                int moves, int killed_white_at[15], int killed_black_at[15], int *flagpassant, int possion_white_at[8], int possion_black_at[8], int *passant_x, char *passant_y) {
    
        if ((strcmp(board[current_x][current_y], "♟")==0) || (strcmp(board[current_x][current_y], "♙")==0))
            paw_move(player,current_x, current_y, to_x, to_y, board, kill_white, kill_black, count_deadWhite, count_deadBlack, flag, moves, killed_white_at, 
            killed_black_at, flagpassant, passant_x, passant_y);
    
        if ((strcmp(board[current_x][current_y], "♛")==0) || (strcmp(board[current_x][current_y], "♕")==0)){
            queen_move(current_x,current_y,to_x,to_y,board,flag);
            eat( player,  current_x,  current_y,to_x, to_y, board,kill_white, kill_black,
            count_deadWhite,count_deadBlack,flag,moves, killed_white_at, killed_black_at);}

        if ((strcmp(board[current_x][current_y], "♚")==0) || (strcmp(board[current_x][current_y], "♔")==0))
        king_move(player, current_x, current_y, to_x, to_y, board, kill_white, kill_black, count_deadWhite,count_deadBlack,flag, moves, killed_white_at, killed_black_at);

        if ((strcmp(board[current_x][current_y], "♝")==0) || (strcmp(board[current_x][current_y], "♗")==0)){
            bishop_move(current_x,current_y,to_x,to_y,board,flag);
            eat( player,  current_x,  current_y,to_x, to_y, board,kill_white, kill_black,
            count_deadWhite,count_deadBlack,flag,moves, killed_white_at, killed_black_at);}
        
        if ((strcmp(board[current_x][current_y], "♜")==0) || (strcmp(board[current_x][current_y], "♖")==0)){
            rook_move(current_x,current_y,to_x,to_y,board,flag);
            eat( player,  current_x,  current_y,to_x, to_y, board,kill_white, kill_black,
            count_deadWhite,count_deadBlack,flag,moves, killed_white_at, killed_black_at);}

        if ((strcmp(board[current_x][current_y], "♞")==0) || (strcmp(board[current_x][current_y], "♘")==0)){
            knight_move(current_x,current_y,to_x,to_y,board,flag);
            eat( player,  current_x,  current_y,to_x, to_y, board,kill_white, kill_black,
            count_deadWhite,count_deadBlack,flag,moves, killed_white_at, killed_black_at);}
}