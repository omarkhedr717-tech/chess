#include <string.h>

void FixBoard(int current_x, int current_y,char board[8][8][32]) {
    if ((current_x + current_y) % 2 == 1) strcpy(board[current_x][current_y] , ".");        //x + y if odd then it's black (.) is black
    else strcpy(board[current_x][current_y] ,"-");
}