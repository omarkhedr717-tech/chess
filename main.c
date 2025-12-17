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
    char kill_white[16][32]={" ", " ", " ", " ", " ", " ", " ", " ",
                            " ", " ", " ", " ", " ", " ", " ", " "};
    char kill_black[16][32]={" ", " ", " ", " ", " ", " ", " ", " ",
                        " ", " ", " ", " ", " ", " ", " ", " "};
    int player=2,current_x,  to_x, count_deadWhite=0,count_deadBlack=0;
    char current_y,to_y;bool flag;
    draw(board, kill_white,kill_black);
while(true){
Input(player, &current_x,&current_y,&to_x, &to_y,board);
queen_move(player,current_x,  current_y,
                  to_x,to_y, board,
                kill_white, kill_black,
                &count_deadWhite,&count_deadBlack,&flag);
    if(!flag){
        printf("Wrong move!\n");
        continue;
    }
    draw(board, kill_white,kill_black);}
    return 0;

}
