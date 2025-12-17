#include"header.h"
void rook_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag){

        *flag = false;int x=current_x,y=current_y;
        if(to_x==current_x||to_y==current_y)
        *flag =true;
        if(to_x>current_x&&to_y==current_y){
            while(++x<to_x){
                if(check_white(x,y,board)||check_black(x,y,board))
                    *flag = false;
            }
        }else if(to_x<current_x&&to_y==current_y){
            while(--x>to_x){
                if(check_white(x,y,board)||check_black(x,y,board))
                    *flag = false;
            }
        }else if(to_x==current_x&&to_y<current_y){
            while(--y>to_y){
                if(check_white(x,y,board)||check_black(x,y,board))
                    *flag = false;
            }
        }else if(to_x==current_x&&to_y>current_y){
            while(++y<to_y){
                if(check_white(x,y,board)||check_black(x,y,board))
                    *flag = false;
            }
        }
        if(*flag){
            if(player ==1){
                if(check_black(to_x,to_y,board)) {
                    strcpy(kill_black[(*count_deadBlack)++] , board[to_x][to_y]);
                }
            }else if(player ==2){
                if(check_white(to_x,to_y,board)) 
                    strcpy(kill_white[(*count_deadWhite)++] , board[to_x][to_y]);
            }
            strcpy(board[to_x][to_y] , board[current_x][current_y]);
        }
    }