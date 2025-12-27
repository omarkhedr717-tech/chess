#include"header.h"
bool stalemate(int player, char board[8][8][5]){
bool flag =true;
    char black[6][5]={"♙","♖", "♘", "♗", "♔", "♕"};
    char white[6][5]={"♟","♜", "♞", "♝", "♚", "♛"};
    char rest[6][5];
    int position=0,position1=0,position2=0,position3=0;
    char temp[5];
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
                        if(king_check(player, i, j, board, &position,&position1,&position2, &position3)){
                            strcpy(board[i][j], temp);
                            continue;
                        }   
                        strcpy(board[i][j], temp);
                        if(k==0){
                                if(player ==1){
                                    if ((i < 9) && (i > 0) && (j < 8) && (j > -1)) {
                                        if((!check_white(i-1,j,board))&&(!check_black(i-1,j,board))){
                                        flag=false;
                                        }
                                    }
                                    if ((i < 9) && (i > 0) && (j < 7) && (j > -2)) {
                                        if (check_black(i-1,j+1,board)) {
                                            flag=false;
                                        }
                                    }
                                    if ((i < 9) && (i > 0) && (j < 9) && (j > 0)) {
                                        if (check_black(i-1,j-1,board)){
                                            flag=false;
                                        }
                                    }
                                }
                                else if(player ==2){
                                        if ((i < 7) && (i > -2) && (j < 8) && (j > -1)) {
                                            if((!check_white(i+1,j,board))&&(!check_black(i+1,j,board))){
                                                flag=false;
                                            }
                                        }
                                        if ((i < 7) && (i > -2) && (j < 7) && (j > -2)) {
                                            if (check_white(i+1,j+1,board))
                                                flag=false;
                                        }
                                        if ((i < 7) && (i > -2) && (j < 9) && (j > 0)) {
                                            if (check_white(i+1,j-1,board)){
                                                flag=false;
                                            }
                                        }
                                }
                        }else if (k==1){
                            for(int a =-1;a<2;a++){
                                for(int b =-1 ;b<2;b++){
                                    if ((j+b < 8) && (j+b > -1) && (i+a < 8) && (i+a > -1) && (a==0||b==0) && !(a==0&&b==0)){
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
                                    if((j+b < 8) && (j+b > -1) && (i+a < 8) && (i+a > -1) && (a!=0)&&(b!=0)){
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
                                    if ((j+b < 8) && (j+b > -1) && (i+a < 8) && (i+a > -1) && (a!=0) && (b!=0)){
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
                                        if ((i+a < 8) && (i+a > -1) && (j+b < 8) && (j+b > -1)) {
                                            if(player ==1){
                                                if((!check_white(i+a,j+b,board))&&(!warning(player ,i+a,j+b,board,&position,&position))){
                                                    flag=false;
                                                }
                                            }else if(player ==2){
                                                if((!check_black(i+a,j+b,board))&&!warning(player ,i+a,j+b,board,&position,&position)){
                                                    flag=false;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }else if(k==5){
                            for(int a =-1;a<2;a++){
                                for(int b =-1 ;b<2;b++){
                                    if (a!=0||b!=0){
                                        if ((i+a < 8) && (i+a > -1) && (j+b < 8) && (j+b > -1)) {
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
        }
    return flag;
}