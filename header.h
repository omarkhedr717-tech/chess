#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void draw(char board[8][8][32],char kill_white[8][32],char kill_black[8][32]);
bool check_white(int current_x, int current_y,char board[8][8][32]);
bool check_black(int current_x, int current_y,char board[8][8][32]);
void Input(int player, int *current_x, char *current_y,int *to_x, char *to_y, char board[8][8][32]);
void knight_move(int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],bool *flag);
void bishop_move(int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],bool *flag);
void rook_move(int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],bool *flag);
void queen_move(int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],bool *flag);
void paw_move(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[15][32],char kill_black[15][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag, int moves, int killed_white_at[15], int killed_black_at[15], 
                int *flagpassant, int *passant_x, char *passant_y);
void king_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[15][32],char kill_black[15][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                 int moves, int killed_white_at[15], int killed_black_at[15]);
void FixBoard(int current_x, int current_y,char board[8][8][32]);
void Undo(int current_x, char current_y, int to_x, char to_y, int moves,char savegame[], char board[8][8][32], int count_deadWhite, int count_deadBlack, int killed_white_at[15],
        int killed_black_at[15], char kill_white[15][32], char kill_black[15][32]);
void ReturnKilled(int current_x, char current_y, int to_x, char to_y,int move_before_undo, int *count_deadWhite, int *count_deadBlack,
        int killed_white_at[15], int killed_black_at[15], char kill_white[15][32], char kill_black[15][32], char board[8][8][32], int flag);
void loadgame(int *current_x, char *current_y, int *to_x, char *to_y, int *moveindex, char savegamefile[]);
void CreateFile(char filename[]);
void UpdateFile(char filename[], char savegame[]);
int LoadFile(char filename[], char savegamefile[]);
int Checkpassant(int to_x, char to_y, int *passant_x, char *passant_y, int player, int *flagpassant,char board[8][8][32]);
void Dopassant(int current_x, char current_y ,int to_x, char to_y, int player, int moves,char *flag, int *count_deadBlack, int *count_deadWhite,char kill_black[15][32],
    int killed_black_at[15], char kill_white[15][32], int killed_white_at[15],char board[8][8][32], int *passant_x, char *passant_y);
void PassantOff(int *flagpassant, int *passant_counter, int moves);
void PickPiece(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[15][32],char kill_black[15][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                int moves, int killed_white_at[15], int killed_black_at[15], int *flagpassant, int possion_white_at[8], int possion_black_at[8], int *passant_x, char *passant_y);
bool check_white_pawn(int current_x, int current_y,char board[8][8][32]);
bool check_black_pawn(int current_x, int current_y,char board[8][8][32]);
void eat(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[15][32],char kill_black[15][32],
                int *count_deadWhite,int *count_deadBlack,bool flag,
                 int moves, int killed_white_at[15], int killed_black_at[15]);
bool warning(int player ,int current_x, int current_y, char board[8][8][32]);