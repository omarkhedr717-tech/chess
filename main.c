#include<stdio.h>
#include<stdbool.h>
#include "header.h"
int main(){
    char board[8][8][32] = {
        {"♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖"},
        {"♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙"},
        {"-", ".", "-", ".", ".", "-", ".", "-"},
        {".", "-", ".", "-", "-", ".", "-", "."},
        {"-", ".", "-", ".", ".", "-", ".", "-"},
        {".", "-", ".", "-", "-", ".", "-", "."},
        {"♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟"},
        {"♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"}};
    char kill_white[16][32]={"♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟",
                            "♜", "♞", "♝", "♚", "♛", "♝", "♞", "♜"};
    char kill_black[16][32]={"♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙",
                        "♖", "♘", "♗", "♔", "♕", "♗", "♘", "♖"};
    while (true){
        int player,current_x,  to_x ;
        char current_y,to_y;
    draw( board, kill_white,kill_black);
    Input(int player, int current_x, char current_y) ;
    moveInput(to_x, to_y);  
    }return 0;

}
