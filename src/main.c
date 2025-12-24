#include "header.h"
int main(){
    char board[8][8][32] = {
        {"♖", "♘", "♗", "♕", "♔", "♔", ".", "♖"},
        {"♟", "♙", "♙", "♙", "♙", "♙", ".", "♙"},
        {"-", ".", "-", ".", ".", "-", ".", "-"},
        {"♟", "-", ".", "♟", "-", ".", "♛", "."},
        {"-", "♙", "-", ".", ".", "-", ".", "-"},
        {"♟", "-", ".", "-", "-", ".", "-", "."},
        {"♟", "♟", "♟", "♟", "♟", ".", "♜", "."},
        {"♜", "♞", "♝", "♛", "♚", "-", ".", "♜"}};
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

int flagpassant=0,passant_counter[8],current_passant=1;
int passantIndex=0;
int possion_white_at[8],possion_black_at[8];
int passant_x;
int passant_y;

int promotion_white_at[8], promotion_black_at[8];
char promotion_white_type[8][32], promotion_black_type[8][32];
int BPromotionIndex=0, WPromotionIndex=0;

int check_x, check_y;
int warning_x, warning_y;

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
    }
}

if (flagsave == 0)
    CreateFile(filename);


while(true){
if (flagsave == 1)
    loadgame(&current_x, &current_y, &to_x, &to_y, &moveindex, savegamefile);

if (strlen(savegamefile) == 0) flagsave = 0;

if (flagsave == 0 && flagundo == 0) {
    // if(king_check(player, current_x, current_y, board, &check_x, &check_y, &warning_x, &warning_y)){
    //     if(check_mate(player, current_x, current_y, board, check_x, check_y, &warning_x, &warning_y)){
    //         printf("CHECKMATE!\n");
    //         printf("PLAYER %d WINS THE GAME\n", (player % 2) + 1);
    //         break;
    //     }
    //     printf("CHECK!\n");
    // }
    printf("PLAYER %d\n",player);
    Input(player, &current_x,&current_y,&to_x, &to_y,board);
}
savegame[i++] = current_y+65; savegame[i++] = 8-current_x+48; savegame[i++] = to_y+65; savegame[i++] = 8-to_x+48;
moves=strlen(savegame)-1;



if (moves > 0 ) {
    PickPiece(player,current_x,current_y,to_x,to_y,board,kill_white,kill_black,
        &count_deadWhite,&count_deadBlack,&flag,moves,killed_white_at,killed_black_at,&flagpassant,possion_white_at,possion_black_at,&passant_x,&passant_y, passant_counter, &passantIndex, savegame, promotion_white_at, promotion_white_type, &WPromotionIndex,promotion_black_at, promotion_black_type, &BPromotionIndex);
}

if(!flag){      //if it's invalid remove it from the saving file
savegame[--i] = '\0', savegame[--i] = '\0',savegame[--i] = '\0',savegame[--i] = '\0';
moves=strlen(savegame)-1;
printf("Wrong move!\n");
if (flagsave == 1) {printf("There is wrong move loading stopped\n"); flagsave=0;}
continue;
}

// if(king_check(player, current_x, current_y, board, &check_x, &check_y, &warning_x, &warning_y)){
//     printf("King is in Dangerous!\n");
//     Undo(&current_x, &current_y, &to_x, &to_y, &moves, savegame, board, &count_deadWhite, &count_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black,&player, &flagpassant, passant_counter, promotion_white_at, promotion_white_type, promotion_black_at, promotion_black_type);
//     continue;
// }
draw(board, kill_white,kill_black);

PassantOff(&flagpassant, passant_counter, moves, player ,&current_passant);
if (flagsave == 0) {
    printf("DO YOU WANT TO UNDO OR REDO (1/0)?:\n");
    scanf("%d",&flagundo);
    if (flagsave == 0 && moves > 0 && flagundo == 1)
    Undo(&current_x, &current_y, &to_x, &to_y, &moves, savegame, board, &count_deadWhite, &count_deadBlack, killed_white_at, killed_black_at, kill_white, kill_black,&player, &flagpassant, passant_counter, promotion_white_at, promotion_white_type, promotion_black_at, promotion_black_type);
    flagundo = 0; flagsave=0;
}
draw(board, kill_white,kill_black);

if (flag) player = (player % 2) + 1;

UpdateFile(filename, savegame);
if (moveindex == strlen(savegamefile)) {flagsave = 0;}  //loading is done
}
return 0;
}