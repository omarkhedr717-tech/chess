#include"header.h"
bool warning(int player ,int current_x, int current_y,char board[8][8][32]){
    bool flag =false;
    char black[6][32]={"♙","♖", "♘", "♗", "♔", "♕"};
    char white[6][32]={"♟","♜", "♞", "♝", "♚", "♛"};
    char killers[6][32];
        for(int i =0;i<6;i++){
            if (player == 1){
                strcpy(killers[i] , black[i]);
            }else if(player == 2){
                strcpy(killers[i] , white[i]);
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                for(int k=0;k<6;k++){
                    if(strcmp(killers[k], board[i][j])==0){
                        if(k==0){
                            if(current_x==i+1&&(current_y=j+1||current_y==j-1))
                                flag = true;
                        }
                        else if(k==1){
                            if(current_x==i||current_y==j)
                                flag =true;
                        }else if(k==2){
                            for(int a =-2;a<=2;a++){
                                for(int b =-2;b<=2;b++){
                                    if(a!=0&&b!=0){
                                        if(abs(a)!=abs(b)){
                                            if(current_x==a+i&&current_y==b+j){
                                                flag =true;
                                            }
                                        }
                                    }
                                }
                            }
                        }else if(k==3){
                            if(abs(current_x-current_y)==abs(i-j)||(current_x+current_y)==(i+j))
                                flag =true;
                        }else if(k==4){
                                for(int a =-1;a<2;a++){
                                    for(int b =-1 ;b<2;b++){
                                        if (a!=0||b!=0){
                                            if(i+a==current_x&&j+b==current_y)
                                            flag =true;
                                        }
                                    }
                                }
                        }else if(k==5){
                            if(abs(current_x-current_y)==abs(i-j)||(current_x+current_y)==(i+j))
                                flag =true;
                            else if(current_x==i||current_y==j)
                                flag =true;
                            
                        }
                    }
                }
            }
        }
    return flag;
}