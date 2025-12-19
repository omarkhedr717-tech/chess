#include"header.h"
void knight_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag, int moves, int killed_white_at[16], int killed_black_at[16]){
*flag = false;
            for(int i =-2;i<=2;i++){
                for(int j =-2;j<=2;j++){
                    if(i!=0&&j!=0){
                        if(abs(i)!=abs(j)){
                            if(to_x==current_x+i&&to_y==current_y+j){
                                *flag = true;
                                if(player ==1){
                                   if(check_black(to_x,to_y,board)) {
                                        strcpy(kill_black[(*count_deadBlack)++] , board[to_x][to_y]);
                                         killed_black_at[((*count_deadBlack)++)-1] = moves;
                                   }
                                }else if(player ==2){
                                    if(check_white(to_x,to_y,board)) 
                                        strcpy(kill_white[(*count_deadWhite)++] , board[to_x][to_y]);
                                        killed_white_at[((*count_deadBlack)++)-1] = moves;
                                }
                                strcpy(board[to_x][to_y] , board[current_x][current_y]);
                                FixBoard(current_x,current_y,board);
                            }
                        }
                    }
                }
            }
}