#include"header.h"
bool check_white_pawn(int current_x, int current_y,char board[8][8][5]){
    char white[1][5]={"♟"};
    bool flag =false;
        if(strcmp(board[current_x][current_y], white[0])==0)
        flag =true;
    return flag;
}
bool check_black_pawn(int current_x, int current_y,char board[8][8][5]){
    char black[1][5]={"♙"};
    bool flag =false;
        if(strcmp(board[current_x][current_y], black[0])==0)
        flag =true;
    return flag;
}