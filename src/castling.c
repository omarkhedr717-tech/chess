#include "header.h"

void DoCastling(int player, int current_x, int current_y, char board[8][8][32]) {
    if (player == 1) {
        strcpy(board[current_x][current_y+2], "♚");
        FixBoard(current_x, current_y,board);
        strcpy(board[current_x][current_y+1], "♜");
        FixBoard(current_x, current_y+3,board);
    }
    if (player == 2) {
        strcpy(board[current_x][current_y+2], "♔");
        FixBoard(current_x, current_y,board);
        strcpy(board[current_x][current_y+1], "♖");
        FixBoard(current_x, current_y+3,board);
    }
}