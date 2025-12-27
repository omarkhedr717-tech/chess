#include"header.h"
bool check_white(int current_x, int current_y,char board[8][8][5]){
    char white[6][5]={"♟","♜", "♞", "♝", "♚", "♛"};
    bool flag =false;
    for(int i=0;i<6;i++){
        if(strcmp(board[current_x][current_y], white[i])==0)
        flag =true;
    }
    return flag;
}
bool check_black(int current_x, int current_y,char board[8][8][5]){
    char black[6][5]={"♙","♖", "♘", "♗", "♔", "♕"};
    bool flag =false;
    for(int i=0;i<6;i++){
        if(strcmp(board[current_x][current_y], black[i])==0)
        flag =true;
    }
    return flag;
}