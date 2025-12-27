#include"header.h"
void rook_move(int current_x, int current_y,
                 int to_x, int to_y, 
                 char board[8][8][5],bool *flag){

        *flag = false;int x=current_x,y=current_y;
        if(!((current_y == to_y) && (current_x == to_x)) && (to_x==current_x||to_y==current_y))
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
    }