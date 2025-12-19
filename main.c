#include "header.h"
int main(){
    char board[8][8][32] = {
        {"♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖"},
        {"♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙"},
        {"-", ".", "-", ".", ".", "-", ".", "-"},
        {".", "-", ".", "-", "-", ".", "-", "."},
        {"-", ".", "-", ".", ".", "-", ".", "-"},
        {".", "-", ".", "-", "-", ".", "-", "."},
        {"♟", "♘", "♟", "♟", "♟", "♟", "♟", "♟"},
        {"♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"}};
    char kill_white[16][32]={" ", " ", " ", " ", " ", " ", " ", " ",
                            " ", " ", " ", " ", " ", " ", " ", " "};
    char kill_black[16][32]={" ", " ", " ", " ", " ", " ", " ", " ",
                        " ", " ", " ", " ", " ", " ", " ", " "};
    int player=1,current_x,  to_x, count_deadWhite=0,count_deadBlack=0;
    char current_y,to_y;bool flag;
    draw(board, kill_white,kill_black);
char savegame[100000]= {"c1b2b2c3c3g7"};
int moves=strlen(savegame)-1,moveindex=0,i=0;
int move_before_undo;
int flagsave=0,flagundo=0;
int killed_white_at[16],killed_black_at[16];
printf("Do you want to load saved game?: ");
scanf("%d",&flagsave);

while(true){
if (flagsave == 1) {
    current_y = savegame[moveindex++]-97;
    current_x = 8 - (savegame[moveindex++]-48);
    to_y = savegame[moveindex++]-97;
    to_x = 8 - (savegame[moveindex++]-48);
}

if (flagsave == 0 && flagundo == 0) {
    Input(player, &current_x,&current_y,&to_x, &to_y,board);
    savegame[i++] = current_y+97; savegame[i++] = 8-current_x+48; savegame[i++] = to_y+97; savegame[i++] = 8-to_x+48; savegame[i] = '\0';
    moves=strlen(savegame)-1;
}

if (moves > 0) {
bishop_move(player,current_x, current_y, to_x, to_y, board, kill_white, kill_black, &count_deadWhite, &count_deadBlack, &flag, moves, killed_white_at, killed_black_at);}
if(!flag){
    printf("Wrong move!\n");
    continue;
}
if (moveindex == moves+1) {flagsave = 0;}

if (flagundo == 1 && moves > 0) {
    if (move_before_undo == killed_white_at[count_deadWhite-2])  strcpy(board[current_x][current_y] , kill_white[count_deadWhite-2]);
    if (move_before_undo == killed_black_at[count_deadBlack-2])  strcpy(board[current_x][current_y] , kill_black[count_deadBlack-2]);
    moves-=4;
    if (moves < 0) flagundo = 0;
}
draw(board, kill_white,kill_black);

printf("DO YOU WANT TO UNDO?:\n");
scanf("%d",&flagundo);
move_before_undo = moves;
if (flagsave == 0 && moves > 0 && flagundo == 1) {
        Undo(&current_x, &current_y, &to_x, &to_y, moves,savegame);
        savegame[--i] = '\0', savegame[--i] = '\0',savegame[--i] = '\0',savegame[--i] = '\0';
}

draw(board, kill_white,kill_black);

}
return 0;
}
