#include"header.h"
void king_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32], bool *flag, char savegame[]){
*flag =false;
int garbage1=0;
    if (current_x == to_x && to_y == current_y + 2) {
        if ((player == 1 && current_x == 7 && current_y == 4) || (player == 2 && current_x == 0 && current_y == 4)) {
            if (check_white(current_x,current_y+1,board) || check_black(current_x,current_y+1,board) || check_white(current_x,current_y+2,board) || check_black(current_x,current_y+2,board)) return;
            for (int i=0; savegame[i]!='\0' ;i++) {
                if (player == 1 && (savegame[i+1] == '1' && (savegame[i] == 'H' || savegame[i] == 'E')) && (savegame[i+2] != 'G')) return;
                else if (player == 2 && (savegame[i+1] == '8' && (savegame[i] == 'H' || savegame[i] == 'E')) && (savegame[i+2] != 'G')) return;
            }
            if (warning(player , current_x, current_y+1, board,&garbage1,&garbage1) || warning(player , current_x, current_y+2, board,&garbage1,&garbage1)) return;
            else {
                DoCastling(player, current_x, current_y, board);
                *flag = true;
            }
        }
    }
        for(int a =-1;a<2;a++){
            for(int b =-1 ;b<2;b++){
                if (a!=0||b!=0){
                    if(current_x+a==to_x&&current_y+b==to_y){
                            if(!warning(player ,to_x,to_y,board,&garbage1,&garbage1)){
                                *flag=true;
                            }
                    }
                }
            }
        }
    }