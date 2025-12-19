#include"header.h"
void paw_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag){
                    *flag = false;
                    if(player ==1){
                        if(to_x==current_x-2 && to_y==current_y){
                            if(current_x==6){
                                if((!check_black(to_x,to_y,board))&&(!check_white(to_x,to_y,board))){
                                    if((!check_black(to_x+1,to_y,board))&&(!check_white(to_x+1,to_y,board))){
                                    *flag=true;
                                    }
                                }
                            }
                        }else if(to_x==current_x-1 && to_y==current_y){
                            if((!check_black(to_x,to_y,board))&&(!check_white(to_x,to_y,board))){
                                *flag=true;
                            }
                        }else if(to_x==current_x-1 && (to_y==current_y+1 || to_y==current_y-1)){
                            if(check_black(to_x,to_y,board)){
                                strcpy(kill_black[(*count_deadBlack)++] , board[to_x][to_y]);
                                *flag=true;
                            }
                        }
                    }
                    if(player ==2){
                        if(to_x==current_x+2 && to_y==current_y){
                            if(current_x==1){
                                if((!check_black(to_x,to_y,board))&&(!check_white(to_x,to_y,board))){
                                    if((!check_black(to_x-1,to_y,board))&&(!check_white(to_x-1,to_y,board))){
                                    *flag=true;
                                    }
                                }
                            }
                        }else if(to_x==current_x+1 && to_y==current_y){
                            if(!check_black(to_x,to_y,board)&&!check_white(to_x,to_y,board)){
                                *flag=true;
                            }
                        }else if(to_x==current_x+1 && (to_y==current_y+1 || to_y==current_y-1)){
                            if(check_white(to_x,to_y,board)){
                                strcpy(kill_white[(*count_deadWhite)++] , board[to_x][to_y]);
                                *flag=true;
                            }
                        }
                    }
            if(*flag){
            strcpy(board[to_x][to_y] , board[current_x][current_y]);
        }
    }