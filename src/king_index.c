#include"header.h"
bool king_positions_warning(int current_x , int current_y, char board[8][8][32]){
    char white[1][32]={"♚"};
    char black[1][32]={"♔"};
    int kingWhite_x, kingWhite_y, kingBlack_x, kingBlack_y;
        for (int i =0;i<8;i++){
            for (int j =0 ; j<8;j++){
                if (strcmp(board[i][j], white[0])==0){
                     kingWhite_x = i;
                    kingWhite_y = j;
                }
                if (strcmp(board[i][j], black[0])==0){
                     kingBlack_x = i;
                     kingBlack_y = j;
                }
            }
        }
        if((abs(kingWhite_x - kingBlack_x)<=2) && (abs(kingWhite_y - kingBlack_y)<=2)){
            if((abs(kingWhite_x - current_x)<2) && (abs(kingWhite_y - current_y)<2)){
                if((abs(kingBlack_x - current_x)<2) && (abs(kingBlack_y - current_y)<2)){
                return true;
                }
            }
        }
        return false;
}