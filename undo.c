#include"header.h"

void Undo(int *current_x, char *current_y, int *to_x, char *to_y, int moves,char savegame[]) {
        *current_x = 8 - (savegame[moves--]-48);
        *current_y = savegame[moves--]-97;
        *to_x = 8 - (savegame[moves--]-48);
        *to_y = savegame[moves--]-97;
}

void ReturnKilled(int *current_x, char *current_y, int move_before_undo, int *count_deadWhite, int *count_deadBlack,
        int killed_white_at[16], int killed_black_at[16], char kill_white[16][32], char kill_black[16][32], char board[8][8][32]) {
        
        if (move_before_undo == killed_white_at[(*count_deadWhite)-1] && count_deadWhite > 0) {
                strcpy(board[*current_x][*current_y] , kill_white[(*count_deadWhite)-1]);
                strcpy(kill_white[(*count_deadWhite)-1], " ");
                (*count_deadWhite)--;
        }
        if (move_before_undo == killed_black_at[*count_deadBlack-1] && count_deadBlack > 0) {
                strcpy(board[*current_x][*current_y] , kill_black[(*count_deadBlack)-1]);
                strcpy(kill_black[(*count_deadBlack)-1], " ");
                (*count_deadBlack)--;
        }
}

void loadgame(int *current_x, char *current_y, int *to_x, char *to_y, int *moveindex, char savegamefile[]) {
        while(savegamefile[*moveindex] != '\0'){
                *current_y = savegamefile[(*moveindex)++]-97;
                *current_x = 8 - (savegamefile[(*moveindex)++]-48);
                *to_y = savegamefile[(*moveindex)++]-97;
                *to_x = 8 - (savegamefile[(*moveindex)++]-48);
                break;
        }
}