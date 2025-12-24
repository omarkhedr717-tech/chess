#include"header.h"

void Undo(int *current_x, char *current_y, int *to_x, int *to_y, int *moves,char savegame[], char board[8][8][32], int *count_deadWhite, int *count_deadBlack, int killed_white_at[16],
        int killed_black_at[16], char kill_white[16][32], char kill_black[16][32], int *player, int *flagpassant, int passant_counter[8],  int promotion_white_at[8], char promotion_white_type[8][32], int promotion_black_at[8], char promotion_black_type[8][32]) {
        int flag;
        char temp_board[8][8][32];
        int move_before_undo = *moves;
        int temp_player = *player;
        int player_before_undo;
        int undo=0,redo=0;
        int Index=0;


        while (true) {
                while (true) {
                        // if (testwarn == x) undo == 1 break;
                        printf("CHOOSE UNDO OR REDO (1/0) OR (-1) TO EXIT:");
                        scanf(" %d",&flag);
                        if ((flag == 0) || (flag == 1) || (flag == -1)) break;
                        while (getchar() != '\n');
                        }
                if (flag == -1) {
                *player = temp_player;
                break;
                }

                if (flag == 1 && ((*moves) >=3)) {
                if (redo == 1) (*moves)--;
                if (temp_player == 1) player_before_undo = 2; else player_before_undo = 1;

                move_before_undo = *moves;
                *current_x = 8 - (savegame[(*moves)--]-48);
                *current_y = savegame[(*moves)--]-65;
                *to_x = 8 - (savegame[(*moves)--]-48);
                *to_y = savegame[(*moves)--]-65;
                redo = 0, undo = 1;             //player turn zero here!?

                if (*current_x == *to_x && (*to_y)+2 == *current_y){ //undo castling
                UndoCastling(player_before_undo, *to_x, *to_y,board);
                draw(board, kill_white,kill_black);
                continue;
                }
                
                for (int i=0; i<8;i++) {
                        if (passant_counter[i] == 0) {*flagpassant = 0; break;}
                        if(move_before_undo == passant_counter[i] || move_before_undo == passant_counter[i]-4) {*flagpassant = 1; break;}
                        else {*flagpassant = 0;}
                }
                
                if ((player_before_undo == 1 && *current_x == 0) || (player_before_undo == 2 && *current_x == 7)) {
                        for (int i=0; i<8;i++) {
                                if (move_before_undo == promotion_white_at[i]) strcpy(board[*current_x][*current_y], "♟");
                                if (move_before_undo == promotion_black_at[i]) strcpy(board[*current_x][*current_y], "♙");
                        }
                }

                strcpy(board[*to_x][*to_y], board[*current_x][*current_y]);
                FixBoard(*current_x,*current_y,board);
                ReturnKilled(current_x, current_y, to_x, to_y,move_before_undo, count_deadWhite, count_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black, board, flag, flagpassant, passant_counter);
                temp_player = ((temp_player) % 2 ) +1;
                }

                if ((flag == 0) && ((*moves) < (int)strlen(savegame)-1)) { //strlen return unsigned int
                if (undo == 1) (*moves)++;
                if (temp_player == 1) player_before_undo = 2; else player_before_undo = 1;

                *current_y = savegame[(*moves)++]-65;
                *current_x = 8 - (savegame[(*moves)++]-48);
                *to_y = savegame[(*moves)++]-65;
                *to_x = 8 - (savegame[(*moves)++]-48);
                undo = 0; redo = 1;
                
                if ((*current_x) == (*to_x )&& (*to_y) == (*current_y) + 2) {       //redo castling
                DoCastling(player_before_undo, *current_x, *current_y,board);
                draw(board, kill_white,kill_black);
                continue;
                }

                move_before_undo = (*moves)-1;
                for (int i=0; i<8;i++) {
                        if (passant_counter[i] == 0) {*flagpassant = 0; break;}
                        if(move_before_undo == passant_counter[i] || move_before_undo == passant_counter[i]-4) {*flagpassant = 1; Index = i; break;}
                        else {*flagpassant = 0;}
                }

                if ((temp_player == 1 && *to_x == 0) || (temp_player == 2 && *to_x == 7))
                for (int i=0; i<8;i++) {
                        if (move_before_undo == promotion_white_at[i]) strcpy(board[*current_x][*current_y], promotion_white_type[i]);
                        if(move_before_undo == promotion_black_at[i]) strcpy(board[*current_x][*current_y], promotion_black_type[i]);
                }

                ReturnKilled(current_x, current_y, to_x, to_y,move_before_undo, count_deadWhite, count_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black, board, flag, flagpassant, passant_counter);
                strcpy(board[*to_x][*to_y], board[*current_x][*current_y]);
                FixBoard(*current_x,*current_y,board);

                if (*flagpassant == 1 && (move_before_undo != passant_counter[Index]-4)) {FixBoard(*current_x,((*current_y)+1),board);}
                temp_player = ((temp_player) % 2 ) +1;
                }
                draw(board, kill_white,kill_black);
                // if (testwarn)  break;
        }
}

void ReturnKilled(int *current_x, char *current_y, int *to_x, int *to_y,int move_before_undo, int *count_deadWhite, int *count_deadBlack,
        int killed_white_at[16], int killed_black_at[16], char kill_white[16][32], char kill_black[16][32], char board[8][8][32], int flag, int *flagpassant, int passant_counter[8]) {

                int temp_to_x = *to_x;
                int temp_current_x = *current_x;

                if (*flagpassant == 1) {
                int capture_x = *current_x; 
                int capture_y = *to_y;
                }

        if ((*count_deadWhite > 0) && (move_before_undo == killed_white_at[(*count_deadWhite)-1]) && flag == 1) {
                if (*flagpassant == 1) {temp_current_x-=1;}
                strcpy(board[temp_current_x][*current_y] , kill_white[(*count_deadWhite)-1]);
                strcpy(kill_white[(*count_deadWhite)-1], " ");
                (*count_deadWhite)--;
        }
        else if ((*count_deadWhite < 14) && (move_before_undo == killed_white_at[(*count_deadWhite)]) && flag == 0) {
                if ((*flagpassant) == 1) {temp_to_x-=1;}
                strcpy(kill_white[(*count_deadWhite)], board[temp_to_x][*to_y]);
                (*count_deadWhite)++;
        }
        if ((*count_deadBlack > 0) && (move_before_undo == killed_black_at[(*count_deadBlack)-1]) && flag == 1) {
                if ((*flagpassant) == 1) {temp_current_x+=1;}
                strcpy(board[temp_current_x][*current_y] , kill_black[(*count_deadBlack)-1]);
                strcpy(kill_black[(*count_deadBlack)-1], " ");
                (*count_deadBlack)--;
        }
        else if ((*count_deadBlack < 14) && (move_before_undo == killed_black_at[(*count_deadBlack)]) && flag == 0) {
                if ((*flagpassant) == 1) {temp_to_x+=1;}
                strcpy(kill_black[(*count_deadBlack)], board[temp_to_x][*to_y]);
                (*count_deadBlack)++;
        }
}

void loadgame(int *current_x, char *current_y, int *to_x, char *to_y, int *moveindex, char savegamefile[]) {

        while(savegamefile[*moveindex] != '\0'){
                *current_y = savegamefile[(*moveindex)++]-65;
                *current_x = 8 - (savegamefile[(*moveindex)++]-48);
                *to_y = savegamefile[(*moveindex)++]-65;
                *to_x = 8 - (savegamefile[(*moveindex)++]-48);
                break;
        }
}

void UndoCastling(int player, int to_x, int to_y, char board[8][8][32]) {
        if (player == 1) {
        strcpy(board[to_x][to_y], "♚");
        FixBoard(to_x, to_y+2,board);
        strcpy(board[to_x][to_y+3], "♜");
        FixBoard(to_x, to_y+1,board);
        } 
        if (player == 2) {
        strcpy(board[to_x][to_y], "♔");
        FixBoard(to_x, to_y+2,board);
        strcpy(board[to_x][to_y+3], "♖");
        FixBoard(to_x, to_y+1,board);
        }
}