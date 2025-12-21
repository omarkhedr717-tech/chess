#include"header.h"

void Undo(int current_x, char current_y, int to_x, char to_y, int moves,char savegame[], char board[8][8][32], int count_deadWhite, int count_deadBlack, int killed_white_at[15],
        int killed_black_at[15], char kill_white[15][32], char kill_black[15][32]) {
        int flag;
        char temp_board[8][8][32];
        int move_before_undo;
        int temp_deadWhite = count_deadWhite;
        int temp_deadBlack = count_deadBlack;
        int undo=0,redo=0;
        for (int i = 0; i < 8; i++)             //copy current board to temp_board
                for (int j = 0; j < 8; j++) 
                        strcpy(temp_board[i][j], board[i][j]);


        while (true) {
                while (true) {
                        printf("CHOOSE UNDO OR REDO (1/0) OR (-1) TO EXIT:");
                        scanf(" %d",&flag);
                        if ((flag == 0) || (flag == 1) || (flag == -1)) break;
                        while (getchar() != '\n');
                        }
                if (flag == -1) break;
                if (flag == 1 && (moves >=3)) {
                move_before_undo = moves;
                if (redo == 1) moves--;
                current_x = 8 - (savegame[moves--]-48);
                current_y = savegame[moves--]-97;
                to_x = 8 - (savegame[moves--]-48);
                to_y = savegame[moves--]-97;
                redo = 0, undo = 1;
                strcpy(temp_board[to_x][to_y], temp_board[current_x][current_y]);
                ReturnKilled(current_x, current_y, to_x, to_y,move_before_undo, &temp_deadWhite, &temp_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black, temp_board, flag);
                }

                if ((flag == 0) && (moves < (int)strlen(savegame)-1)) {
                if (undo == 1) moves++;
                current_y = savegame[moves++]-97;
                current_x = 8 - (savegame[moves++]-48);
                to_y = savegame[moves++]-97;
                to_x = 8 - (savegame[moves++]-48);
                move_before_undo = moves-1;
                undo = 0; redo = 1;
                ReturnKilled(current_x, current_y, to_x, to_y,move_before_undo, &temp_deadWhite, &temp_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black, temp_board, flag);
                strcpy(temp_board[to_x][to_y], temp_board[current_x][current_y]);
                }
                // FixBoard(current_x,current_y,temp_board);
                draw(temp_board, kill_white,kill_black);
        }
}

void ReturnKilled(int current_x, char current_y, int to_x, char to_y,int move_before_undo, int *count_deadWhite, int *count_deadBlack,
        int killed_white_at[15], int killed_black_at[15], char kill_white[15][32], char kill_black[15][32], char board[8][8][32], int flag) {
        if (move_before_undo == killed_white_at[(*count_deadWhite)-1]) {
                if (flag == 1) {
                strcpy(board[current_x][current_y] , kill_white[(*count_deadWhite)-1]);
                strcpy(kill_white[(*count_deadWhite)-1], " ");
                if((*count_deadWhite)>0)
                (*count_deadWhite)--;
                }
                else {
                if((*count_deadWhite)<14)
                (*count_deadWhite)++;
                strcpy(kill_white[(*count_deadWhite)-1], board[to_x][to_y]);
                }
        }
        if (move_before_undo == killed_black_at[(*count_deadBlack)-1]) {
                if (flag == 1) {
                strcpy(board[current_x][current_y] , kill_black[(*count_deadBlack)-1]);
                strcpy(kill_black[(*count_deadBlack)-1], " ");
                if((*count_deadWhite)>0)
                (*count_deadBlack)--;
                }
                else {
                if((*count_deadWhite)<14)
                (*count_deadBlack)++;
                strcpy(kill_black[(*count_deadBlack)-1], board[to_x][to_y]);
                }
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