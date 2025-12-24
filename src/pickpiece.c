#include "header.h"

void PickPiece(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                int moves, int killed_white_at[16], int killed_black_at[16], int *flagpassant, int possion_white_at[8], int possion_black_at[8], 
                int *passant_x, char *passant_y, int passant_counter[8], int *passantIndex, char savegame[], int promotion_white_at[8], char promotion_white_type[8][32], 
                int *WPromotionIndex,int promotion_black_at[8], char promotion_black_type[8][32], int *BPromotionIndex) {
    
        if ((strcmp(board[current_x][current_y], "♟")==0) || (strcmp(board[current_x][current_y], "♙")==0))
        paw_move(player,  current_x,  current_y,  to_x,  to_y,  board,  kill_white, kill_black,
                 count_deadWhite, count_deadBlack, flag,  moves,  killed_white_at,  killed_black_at, 
                 flagpassant,  passant_x,  passant_y,  passant_counter,  passantIndex,  promotion_white_at,  promotion_white_type, WPromotionIndex, promotion_black_at,  promotion_black_type,  BPromotionIndex);
    
        if ((strcmp(board[current_x][current_y], "♛")==0) || (strcmp(board[current_x][current_y], "♕")==0)){
            queen_move(current_x,current_y,to_x,to_y,board,flag);
            eat( player,  current_x,  current_y,to_x, to_y, board,kill_white, kill_black,
            count_deadWhite,count_deadBlack,flag,moves, killed_white_at, killed_black_at);}

        if ((strcmp(board[current_x][current_y], "♚")==0) || (strcmp(board[current_x][current_y], "♔")==0)){
            king_move(player, current_x, current_y, to_x, to_y, board, flag, savegame);
            eat( player,  current_x,  current_y,to_x, to_y, board,kill_white, kill_black,
            count_deadWhite,count_deadBlack,flag,moves, killed_white_at, killed_black_at);}

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