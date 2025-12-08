#include <string.h>

void FixBoard(int current_x, int current_y,char board[8][8]) {
    if ((current_x + current_y) % 2 == 1) board[current_x][current_y] = '.';        //x + y if odd then it's black (.) is black
    else board[current_x][current_y] = '_';
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
