#include<stdio.h>
int main(){
    char board[8][8][32] = {
        {"♖", "♘", "♗", "♔", "♕", "♗", "♘", "♖"},
        {"♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙"},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {"♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟"},
        {"♜", "♞", "♝", "♚", "♛", "♝", "♞", "♜"}
        
        
    };
    char kill_white[16][32]={"♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟",
                            "♜", "♞", "♝", "♚", "♛", "♝", "♞", "♜"};
    char kill_black[16][32]={"♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙",
                        "♖", "♘", "♗", "♔", "♕", "♗", "♘", "♖"};
    
    char col ='A';
    int x = 8;
    for(int i=0 ; i <8 ;i++){
        if(i == 0){
            printf("\n  ");
            for(int n=0;n<8;n++){printf("  %c ",col+n);}
            printf("    White Black\n  ");}
        for(int k=0;k<8;k++){ printf("|---");}  
        printf("|     %s     %s\n%d ",kill_white[i],kill_black[i],x-i);
        for(int j=0;j<8;j++){ printf("| %s ",board[i][j]);}  
        printf("| %d   %s     %s\n  ",x-i,kill_white[i+8],kill_black[i+8]);
        fflush(stdout);
            if (i==7){
                for(int k=0;k<8;k++){printf("|---");}
                printf("|\n  ");
                for(int n=0;n<8;n++){printf("  %c ",col+n);}
                printf("\n");}
        }
        return 0;
}
