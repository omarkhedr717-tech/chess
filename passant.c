#include "header.h"

void Checkpassant(int to_x, char to_y, int *passant_x, char *passant_y, int player, char *flagpassant,char board[8][8][32]) {
    if (player == 1)
        if (check_black_pawn(to_x,to_y-1,board) || check_black_pawn(to_x,to_y+1,board)) {
            *passant_x = to_x+1; *passant_y = to_y;
            *flagpassant=1;
        }
    if (player == 2) 
        if (check_white_pawn(to_x,to_y-1,board) || check_white_pawn(to_x,to_y+1,board)) {
            *passant_x = to_x-1; *passant_y = to_y;
            *flagpassant=1;
        }
}

void Dopassant(int current_x, char current_y ,int to_x, char to_y, int player, int moves,char *flag, int *count_deadBlack, int *count_deadWhite,char kill_black[16][32],
    int killed_black_at[16], char kill_white[16][32], int killed_white_at[16],char board[8][8][32], int *passant_x, char *passant_y) {
    if (player == 1 && (*passant_x == to_x) && (*passant_y == to_y)) {
    strcpy(kill_black[(*count_deadBlack)++] , "♙");
    if (to_y == current_y+1)
        FixBoard(current_x,current_y+1,board);
    if (to_y == current_y-1)
        FixBoard(current_x,current_y-1,board);
    killed_black_at[*count_deadBlack-1] = moves;
    *flag=true;
    }
    if (player == 2 && (*passant_x == to_x) && (*passant_y == to_y)) {
    strcpy(kill_white[(*count_deadWhite)++] , "♟");
    if (to_y == current_y+1)
        FixBoard(current_x,current_y+1,board);
    if (to_y == current_y-1)
        FixBoard(current_x,current_y-1,board);
    killed_white_at[*count_deadWhite-1] = moves;
    *flag=true;
    }
}

void PassantOff(int *flagpassant, int *passant_counter, int moves) {
    if (moves == (*passant_counter)+4) *flagpassant = 0;
    if (*flagpassant == 1) *passant_counter = moves;
}