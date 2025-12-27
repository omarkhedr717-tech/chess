#include"header.h"
bool warning(int player ,int current_x, int current_y,char board[8][8][5],int *warning_x,int *warning_y){
    bool flag =false;
    char black[6][5]={"♙","♖", "♘", "♗", "♔", "♕"};
    char white[6][5]={"♟","♜", "♞", "♝", "♚", "♛"};
    char killers[6][5];

    int position=0;
        for(int i =0;i<6;i++){
            if (player == 1){
                strcpy(killers[i] , black[i]);
            }else if(player == 2){
                strcpy(killers[i] , white[i]);
            }
        }
        for(int i=0;i<8;i++){
            if (flag) break;
            for(int j=0;j<8;j++){
                if (flag) break;
                for(int k=0;k<6;k++){
                    if (flag) break;
                    if(strcmp(killers[k], board[i][j])==0){
                        if(k==0){
                            if(player ==1){
                                if(current_x==i+1&&(current_y==j+1||current_y==j-1)) {
                                    flag = true;
                                    *warning_x = i; *warning_y = j;
                                }
                            }
                            if(player ==2){
                                if(current_x==i-1&&(current_y==j+1||current_y==j-1)) {
                                    flag = true;
                                    *warning_x = i; *warning_y = j;
                                }
                            }
                        }
                        else if(k==1){
rook_move(i,j,current_x,current_y,board,&flag);
if(flag) {*warning_x = i; *warning_y = j;}
                        }else if(k==2){
knight_move(i,j,current_x,current_y,board,&flag);
if(flag) {*warning_x = i; *warning_y = j;}
                        }else if(k==3){
bishop_move(i,j,current_x,current_y,board,&flag);
if(flag) {*warning_x = i; *warning_y = j;}
                        }else if(k==4){
            for(int a =-1;a<2;a++){
                for(int b =-1 ;b<2;b++){
                    if (a!=0||b!=0){
                        if(i+a==current_x&&i+b==current_y){
                            flag=true;
                            *warning_x = i; *warning_y = j;
                        }
                    }
                }
            }
        }
                    else if(k==5){
queen_move(i,j,current_x,current_y,board,&flag);
if(flag) {*warning_x = i; *warning_y = j;}
                        }
                    }
                }
            }
        }
    return flag;
}