#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
void draw(char board[8][8][32],char kill_white[8][32],char kill_black[8][32]);
bool check_white(int current_x, int current_y,char board[8][8][32]);
bool check_black(int current_x, int current_y,char board[8][8][32]);
void Input(int player, 
    int *current_x, char *current_y,
    int *to_x, char *to_y, 
    char board[8][8][32]);
    void knight_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag);
    void bishop_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag);
    void rook_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag);
    void queen_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag);
                
void FixBoard(int current_x, int current_y,char board[8][8]);
char Promotion(int to_x);
void PowMove(int player, int current_x, int current_y, int to_x, int to_y, char board[8][8]);