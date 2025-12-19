#include"header.h"
void king_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag){
*flag =false;
                    
        for(int a =-1;a<2;a++){
            for(int b =-1 ;b<2;b++){
                if (a!=0||b!=0){
                    if(current_x+a==to_x&&current_y+b==to_y){
                            if(!warning(player ,current_x,current_y,board)){
                                if(player ==1){
                                    if(check_black(to_x,to_y,board)) {
                                        strcpy(kill_black[(*count_deadBlack)++] , board[to_x][to_y]);
                                    }
                                }else if(player ==2){
                                    if(check_white(to_x,to_y,board)){ 
                                        strcpy(kill_white[(*count_deadWhite)++] , board[to_x][to_y]);
                                    }
                                }
                                strcpy(board[to_x][to_y] , board[current_x][current_y]);
                                *flag=true;
                            }
                    }
                }
            }
        }
    }