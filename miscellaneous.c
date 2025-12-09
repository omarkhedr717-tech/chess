#include <string.h>

void FixBoard(int current_x, int current_y,char board[8][8][32]) {
    if ((current_x + current_y) % 2 == 1) strcpy(board[current_x][current_y] , ".");        //x + y if odd then it's black (.) is black
    else strcpy(board[current_x][current_y] ,"-");
}

char Promotion(int to_x) {
    char promote,flag=1;
    printf("What do you want to Promote To ");
    while (flag) {
    scanf("%c",&promote);
    if (to_x == 0 && strchr("PRNBQ",promote))
        return promote;
    if (to_x == 7 && strchr("prnbq",promote))
        return promote;
    }
}
