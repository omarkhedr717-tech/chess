#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void draw(char board[8][8][32],char kill_white[16][32],char kill_black[16][32]);
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
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag, int moves, int killed_white_at[16], int killed_black_at[16], 
                int *flagpassant, int *passant_x, int *passant_y, int passant_counter[8], int *passantIndex, int promotion_white_at[8], 
                char promotion_white_type[8][32], int *WPromotionIndex,int promotion_black_at[8],
                 char promotion_black_type[8][32], int *BPromotionIndex, int *moves_draw, int *flagsave, int *promotion_index, int promotion_hist[]);
void king_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32], bool *flag, char savegame[]);
void FixBoard(int current_x, int current_y,char board[8][8][32]);
void Undo(int *current_x, char *current_y, int *to_x, int *to_y, int *moves,char savegame[], char board[8][8][32], int *count_deadWhite, int *count_deadBlack, int killed_white_at[16],
        int killed_black_at[16], char kill_white[16][32], char kill_black[16][32], int *player, 
        int *flagpassant, int passant_counter[8],  int promotion_white_at[8], char promotion_white_type[8][32], 
        int promotion_black_at[8], char promotion_black_type[8][32], int flagwarn, int *i, int *passant_index, int drawmovehist[], int *drawhistindex,
        int *white_promotion, int *black_promotion, int promotion_hist[], int *promotion_index);
void ReturnKilled(int *current_x, char *current_y, int *to_x, int *to_y,int move_before_undo, int *count_deadWhite, int *count_deadBlack,
        int killed_white_at[16], int killed_black_at[16], char kill_white[16][32], char kill_black[16][32], char board[8][8][32], int flag, int *flagpassant, int passant_counter[8]);
void loadgame(int *current_x, char *current_y, int *to_x, char *to_y, int *moveindex, char savegamefile[]);
void CreateFile(char filename[]);
void UpdateFile(char filename[], char savegame[], int promotion_hist[], int draw_hist);
int LoadFile(char filename[], char savegamefile[], int promotion_hist[], int *draw_hist);
void Checkpassant(int to_x, int to_y, int *passant_x, char *passant_y, int player, int *flagpassant,char board[8][8][32]);
void Dopassant(int current_x, char current_y ,int to_x, int to_y, int player, int moves,char *flag, int *count_deadBlack, int *count_deadWhite,char kill_black[16][32],
    int killed_black_at[16], char kill_white[16][32], int killed_white_at[16],char board[8][8][32], int *passant_x, char *passant_y, int passant_counter[8], int *passantIndex);
void PassantOff(int *flagpassant, int passant_counter[8], int moves, int player ,int *current_passant);
void PickPiece(int player, int current_x, int current_y,
                int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool *flag,
                int moves, int killed_white_at[16], int killed_black_at[16], int *flagpassant, int possion_white_at[8], int possion_black_at[8], 
                int *passant_x, char *passant_y, int passant_counter[8], int *passantIndex, char savegame[], int promotion_white_at[8], char promotion_white_type[8][32], 
                int *WPromotionIndex,int promotion_black_at[8], char promotion_black_type[8][32], int *BPromotionIndex, int *moves_draw, int *flagsave, int *promotion_index, int promotion_hist[]);
bool check_white_pawn(int current_x, int current_y,char board[8][8][32]);
bool check_black_pawn(int current_x, int current_y,char board[8][8][32]);
void eat(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][32],
                char kill_white[16][32],char kill_black[16][32],
                int *count_deadWhite,int *count_deadBlack,bool flag,
                 int moves, int killed_white_at[16], int killed_black_at[16]);
bool warning(int player ,int current_x, int current_y,char board[8][8][32],int *warning_x,int *warning_y);
void DoCastling(int player, int current_x, int current_y, char board[8][8][32]);
void UndoCastling(int player, int to_x, int to_y, char board[8][8][32]);
void Checkdraw50(int count_deadWhite, int count_deadBlack, int *white_draw, int *black_draw, int *moves_draw, int *flagdraw50, int flagsave, int *draw_hist);
bool stalemate(int player, char board[8][8][32]);
bool king_check(int player,int current_x, int current_y,char board[8][8][32],
    int *check_x,int *check_y, int *warning_x, int *warning_y);
bool check_mate(int player ,int current_x, int current_y,char board[8][8][32],int check_x,int check_y, int *warning_x, int *warning_y);
bool king_positions_warning(int current_x , int current_y, char board[8][8][32]);