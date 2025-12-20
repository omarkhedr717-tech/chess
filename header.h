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
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                int moves, int killed_white_at[16], int killed_black_at[16]);
    void bishop_move(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag, int moves,
                int killed_white_at[16], int killed_black_at[16]);
    void rook_move(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                int moves, int killed_white_at[16], int killed_black_at[16]);
void queen_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,  
                int moves, int killed_white_at[16], int killed_black_at[16]);
    void paw_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag, int moves, int killed_white_at[16], int killed_black_at[16], 
                int *flagpassant, int possion_white_at[8], int possion_black_at[8], int *passant_x, char *passant_y);
    void king_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag);
                

void FixBoard(int current_x, int current_y,char board[8][8][32]);
void Undo(int *current_x, char *current_y, int *to_x, char *to_y, int moves,char savegame[]);
void ReturnKilled(int *current_x, char *current_y, int move_before_undo, int *count_deadWhite, int *count_deadBlack,
        int killed_white_at[16], int killed_black_at[16], char kill_white[16][32], char kill_black[16][32], char board[8][8][32]);
void loadgame(int *current_x, char *current_y, int *to_x, char *to_y, int *moveindex, char savegamefile[]);

void CreateFile(char filename[]);
void UpdateFile(char filename[], char savegame[]);
int LoadFile(char filename[], char savegamefile[]);

int Checkpassant(int to_x, char to_y, int *passant_x, char *passant_y, int player, int *flagpassant,char board[8][8][32]);
void Dopassant(int current_x, char current_y ,int to_x, char to_y, int player, int moves,int *flag, int *count_deadBlack, int *count_deadWhite,char kill_black[16][32],
    int possion_black_at[16], char kill_white[16][32], int possion_white_at[16],char board[8][8][32], int *passant_x, char *passant_y);
void PassantOff(int *flagpassant, int *passant_counter, int moves);