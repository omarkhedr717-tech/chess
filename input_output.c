#include <stdio.h>
#include <string.h>
#include<stdbool.h>

char *Input(int player, 
    int *current_x, char *current_y,
    int *to_x, char *to_y, 
    char *killer,char *killed,
    char board[8][8][32])
     {
    int flag = true;
    while (flag) {
        scanf(" %c%d", &*current_y, &*current_x);
        *current_y = *current_y - 97;
        *current_x = 8 - *current_x;
        scanf(" %c%d", &*to_y, &*to_x);
        *to_y = *to_y - 97;
        *to_x = 8 - *to_x;
        if (*current_x >= 0 && *current_x <= 7 && *current_y >= 0 && *current_y <= 7) {
            if (player == 1){
                if (strchr("♟♜♞♝♛♚", board[*current_x][*current_y])) {
                    if (!strchr("♙♖♘♗♔♕", board[*to_x][*to_y])) {
                        flag = false;}}}

            if (player == 2){
                if (strchr("♙♖♘♗♔♕", board[*current_x][*current_y])) {
                    if (!strchr("♟♜♞♝♛♚", board[*to_x][*to_y])) {
                        flag = false;}}}
            } else printf("Wrong Move!\n");
        }
    }