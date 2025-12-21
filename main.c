#include "header.h"
int main(){
    char board[8][8][32] = {
        {"♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖"},
        {"♟", "♟", "♙", "♙", "♙", "♙", "♙", "♟"},
        {"-", ".", "-", ".", ".", "-", ".", "-"},
        {"♟", "-", ".", "-", "-", ".", "-", "."},
        {"-", "♙", "-", ".", ".", "-", ".", "-"},
        {".", "♙", ".", "-", "-", ".", "-", "."},
        {"♘", "♘", "♟", "♟", "♟", "♟", "♟", "♘"},
        {"♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"}};
    char kill_white[16][32]={" ", " ", " ", " ", " ", " ", " ", " ",
                            " ", " ", " ", " ", " ", " ", " ", " "};
    char kill_black[16][32]={" ", " ", " ", " ", " ", " ", " ", " ",
                        " ", " ", " ", " ", " ", " ", " ", " "};
    int player=1,current_x,  to_x, count_deadWhite=0,count_deadBlack=0;
    char current_y,to_y;bool flag;
    draw(board, kill_white,kill_black);

char filename[100];
char savegamefile[100000]= {""};
char savegame[100000]= {""};
int moves=strlen(savegame)-1,moveindex=0,i=0;
int move_before_undo;
int flagsave=-1,flagundo=0;

int killed_white_at[16],killed_black_at[16];
int flagpassant=0,passant_counter=0;
int possion_white_at[8],possion_black_at[8];
int passant_x;
char passant_y;

FILE *fp;
while (true) {
printf("Do you want to load saved game (1/0)?: ");
scanf(" %d",&flagsave);
if ((flagsave == 1) || (flagsave==0)) break;
while (getchar() != '\n');
}

if (flagsave == 1) {
    printf("WHICH GAME SAVE?: \n");
    scanf("%s",filename);
    while(LoadFile(filename, savegamefile)) {
        scanf("%s",filename);
    };
}

if (flagsave == 0)
    CreateFile(filename);


while(true){
if (flagsave == 1)
    loadgame(&current_x, &current_y, &to_x, &to_y, &moveindex, savegamefile);

if (flagsave == 0 && flagundo == 0) {
    printf("PLAYER %d\n",player);
    Input(player, &current_x,&current_y,&to_x, &to_y,board);
    savegame[i++] = current_y+97; savegame[i++] = 8-current_x+48; savegame[i++] = to_y+97; savegame[i++] = 8-to_x+48;
    moves=strlen(savegame)-1;
}



if (moves > 0 ) {
    PickPiece(player,current_x,current_y,to_x,to_y,board,kill_white,kill_black,
        &count_deadWhite,&count_deadBlack,&flag,moves,killed_white_at,killed_black_at,&flagpassant,possion_white_at,possion_black_at,&passant_x,&passant_y);
    PassantOff(&flagpassant, &passant_counter, moves);
}

if(!flag){      //if it's invalid remove it from the saving file
savegame[--i] = '\0', savegame[--i] = '\0',savegame[--i] = '\0',savegame[--i] = '\0';
moves=strlen(savegame)-1;
printf("Wrong move!\n");
if (flagsave == 1) {printf("There is wrong move loading stopped\n"); flagsave=0;}
continue;
}

draw(board, kill_white,kill_black);

if (flagsave == 0) {
    printf("DO YOU WANT TO UNDO OR REDO (1/0)?:\n");
    scanf("%d",&flagundo);
    if (flagsave == 0 && moves > 0 && flagundo == 1)
    Undo(current_x, current_y, to_x, to_y, moves, savegame, board, count_deadWhite, count_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black);
}
if (flag) player = (player % 2) + 1;
draw(board, kill_white,kill_black);

UpdateFile(filename, savegame);
if (moveindex == strlen(savegamefile)) {flagsave = 0;}  //loading is done
}
return 0;
}
