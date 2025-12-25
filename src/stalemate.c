#include"header.h"
bool stalemate(int player, char board[8][8][32]){
bool flag =true;
    char black[6][32]={"♙","♖", "♘", "♗", "♔", "♕"};
    char white[6][32]={"♟","♜", "♞", "♝", "♚", "♛"};
    char rest[6][32];
    int q, w;
    char temp[32];
        for(int i =0;i<6;i++){
            if (player == 1){
                strcpy(rest[i] , white[i]);
            }else if(player == 2){
                strcpy(rest[i] , black[i]);
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                for(int k=0;k<6;k++){
                    if(strcmp(rest[k], board[i][j])==0){
                        strcpy(temp, board[i][j]);
                        FixBoard(i,j,board);
                        if(king_check(player, i, j, board, &q, &w)){
                            strcpy(board[i][j], temp);
                            continue;
                        }   
                        strcpy(board[i][j], temp);
                        if(k==0){
                                if(player ==1){
                                    if((!check_white(i-1,j,board))&&(!check_black(i-1,j,board))){
                                        flag=false;
                                    }else if(check_black(i-1,j+1,board)||check_black(i-1,j-1,board)){
                                        flag=false;
                                    }
                                }else if(player ==2){
                                    if((!check_white(i+1,j,board))&&(!check_black(i+1,j,board))){
                                        flag=false;
                                    }else if(check_black(i+1,j+1,board)||check_black(i+1,j-1,board)){
                                        flag=false;
                                    }
                                }
                        }else if (k==1){
                            for(int a =-1;a<2;a++){
                                for(int b =-1 ;b<2;b++){
                                    if ((a==0||b==0) && !(a==0&&b==0)){
                                        if(player ==1){
                                            if(!check_white(i+a,j+b,board)){
                                                flag=false;
                                            }
                                        }else if(player ==2){
                                            if(!check_black(i+a,j+b,board)){
                                                flag=false;
                                            }
                                        }
                                    }
                                }
                            }
                        }else if (k==2){
                            for(int a =-2;a<=2;a++){
                                for(int b =-2;b<=2;b++){
                                    if(a!=0&&b!=0){
                                        if(abs(a)!=abs(b)){
                                            if(player ==1){
                                                if(!check_white(i+a,j+b,board)){
                                                    flag=false;
                                                }
                                            }else if(player ==2){
                                                if(!check_black(i+a,j+b,board)){
                                                    flag=false;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if(k==3){
                            for(int a =-1;a<2;a++){
                                for(int b =-1 ;b<2;b++){
                                    if (a!=0&&b!=0){
                                        if(player ==1){
                                            if(!check_white(i+a,j+b,board)){
                                                flag=false;
                                            }
                                        }else if(player ==2){
                                            if(!check_black(i+a,j+b,board)){
                                                flag=false;
                                            }
                                        }
                                    }
                                }
                            }
                        }else if(k==4){
                            for(int a =-1;a<2;a++){
                                for(int b =-1 ;b<2;b++){
                                    if (a!=0||b!=0){
                                        if(player ==1){
                                            if((!check_white(i+a,j+b,board))&&(!warning(player ,i+a,j+b,board,&q,&w))){
                                                flag=false;
                                            }
                                        }else if(player ==2){
                                            if((!check_black(i+a,j+b,board))&&!warning(player ,i+a,j+b,board,&q,&w)){
                                                flag=false;
                                            }
                                        }
                                    }
                                }
                            }
                        }else if(k==5){
                            for(int a =-1;a<2;a++){
                                for(int b =-1 ;b<2;b++){
                                    if (a!=0||b!=0){
                                        if(player ==1){
                                            if(!check_white(i+a,j+b,board)){
                                                flag=false;
                                            }
                                        }else if(player ==2){
                                            if(!check_black(i+a,j+b,board)){
                                                flag=false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    return flag;
}