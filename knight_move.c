#include"header.h"
void knight_move(int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],bool *flag){
*flag = false;
            for(int i =-2;i<=2;i++){
                for(int j =-2;j<=2;j++){
                    if(i!=0&&j!=0){
                        if(abs(i)!=abs(j)){
                            if(to_x==current_x+i&&to_y==current_y+j){
                                *flag = true;
                            }
                        }
                    }
                }
            }
}