#include"header.h"
bool king_check(int player,int current_x, int current_y,char board[8][8][32],
    int *check_x,int *check_y, int *warning_x, int *warning_y){
    char white[1][32]={"♚"};
    char black[1][32]={"♔"};
    char king[1][32];
        if (player == 1){
            strcpy(king[0] , white[0]);
        }else if(player == 2){
            strcpy(king[0] , black[0]);
        }
    bool flag =false;
        for (int i =0;i<8;i++){
            for (int j =0 ; j<8;j++){
                if (strcmp(board[i][j], king[0])==0){
                    if(warning(player ,i, j,board,warning_x,warning_y)) {
                        *check_x = i ;*check_y=j;
                        flag =true;
                    }
                }
            }

        }
    return flag;
}
bool check_mate(int player ,int current_x, int current_y,char board[8][8][32],int check_x,int check_y, int *warning_x, int *warning_y){
    bool flag =true;
    for(int a =-1;a<2;a++){
        for(int b =-1 ;b<2;b++){
            if (a!=0||b!=0){
                if ((check_x+a < 8) && (check_x+a > -1) && (check_y+b < 8) && (check_y+b > -1)) {
                    if(!warning(player ,check_x+a,check_y+b,board,warning_x,warning_y)){
                        if(player == 1) {
                            if (!check_white(check_x+a,check_y+b,board))
                                flag=false;
                        }else if (player == 2) {
                                if (!check_black(check_x+a,check_y+b,board))
                                flag=false;
                        }
                    }
                }
            }
        }
    }
    char black[3][32]={"♖","♗","♕"};
    char white[6][32]={"♜","♝","♛"};
    char killers[3][32];
    for(int i=0;i<3;i++){
        if (player == 1){
            strcpy(killers[i] , black[i]);
        }else if(player == 2){
            strcpy(killers[i] , white[i]);
        }
    }
    player = (player%2)+1;
    int x=*warning_x,y=*warning_y;
        if(warning(player ,x,y,board,warning_x,warning_y))
            flag = false;
    if(strcmp(killers[0], board[check_x][check_y])==0){
        if(check_x==*warning_x||check_y==*warning_y){
            
        if(*warning_x<check_x&&check_y==current_y){
            while(++x<check_x){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(*warning_x>check_x&&check_y==current_y){
            while(--x>check_x){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(*warning_x==check_x&&check_y<*warning_y){
            while(--y>check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(*warning_x==check_x&&check_y>*warning_y){
            while(++y<check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }
        }
    }else if(strcmp(killers[1], board[check_x][check_y])==0){
        if(abs(check_x-check_y)==abs(current_x-current_y)||(check_x+check_y)==(x+y)){
        if(check_x>x&&check_y>y){
            while(++x<check_x&&++y<check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(check_x<current_x&&check_y<current_y){
            while(--x>check_x&&--y>check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(check_x>current_x&&check_y<current_y){
            while(++x<check_x&&--y>check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(check_x<current_x&&check_y>current_y){
            while(--x>check_x&&++y<check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }
    }
    }else if(strcmp(killers[2], board[check_x][check_y])==0){
        if(abs(check_x-check_y)==abs(x-y)||(check_x+check_y)==(x+y)
            || check_x==x||check_y==y){
        if(check_x>=x&&check_y>=y){
            if(check_x==x){
                while(++y<check_y){
                    if(warning(player ,x, y,board,warning_x,warning_y))
                        flag = false;
                }
            }else if(check_y==y){
                while(++x<check_x){
                    if(warning(player ,x, y,board,warning_x,warning_y))
                        flag = false;
                }
            }else{
            while(++x<check_x&&++y<check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;}
            }
        }else if(check_x<=x&&check_y<=y){
            if(check_y==y){
                while(--x>check_x){
                    if(warning(player ,x, y,board,warning_x,warning_y))
                        flag = false;
                }
            }else if(check_x==x){
                while(--y>check_y){
                    if(warning(player ,x, y,board,warning_x,warning_y))
                        flag = false;
                }
            }else{
                while(--x>check_x&&--y>check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
                }
            }
        }else if(check_x>x&&check_y<current_y){
            while(++x<check_x&&--y>check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }else if(check_x<x&&check_y>y){
            while(--x>check_x&&++y<check_y){
                if(warning(player ,x, y,board,warning_x,warning_y))
                    flag = false;
            }
        }
    }
}
    return flag;
}  