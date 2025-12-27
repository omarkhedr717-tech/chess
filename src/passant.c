#include "header.h"

void Checkpassant(int to_x, int to_y, int *passant_x, char *passant_y, int player, int *flagpassant,char board[8][8][5]) {
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

void Dopassant(int current_x, char current_y ,int to_x, int to_y, int player, int moves,char *flag, int *count_deadBlack, int *count_deadWhite,char kill_black[16][5],
    int killed_black_at[16], char kill_white[16][5], int killed_white_at[16],char board[8][8][5], int *passant_x, char *passant_y, int passant_counter[8], int *passantIndex) {
    if (player == 1) {
    strcpy(kill_black[(*count_deadBlack)++] , "♙");
    if (to_y == current_y+1)
        FixBoard(current_x,current_y+1,board);
    if (to_y == current_y-1)
        FixBoard(current_x,current_y-1,board);
    killed_black_at[*count_deadBlack-1] = moves;
    
    *flag=true;
    }
    if (player == 2) {
    strcpy(kill_white[(*count_deadWhite)++] , "♟");
    if (to_y == current_y+1)
        FixBoard(current_x,current_y+1,board);
    if (to_y == current_y-1)
        FixBoard(current_x,current_y-1,board);
    killed_white_at[*count_deadWhite-1] = moves;
    *flag=true;
    }
    passant_counter[*passantIndex] = moves;
    (*passantIndex)++;

}

void PassantOff(int *flagpassant, int passant_counter[8], int moves, int player, int *current_passant) {
    if (moves == (*current_passant)+4) *flagpassant = 0;
    if (*flagpassant == 1) *current_passant = moves;
}