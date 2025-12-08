#include <stdio.h>
#include <string.h>

void Input(int player, int *current_x, char *current_y, char board[8][8]) {
    int flag = 1;
    while (flag) {
        scanf("%c %d", &*current_y, &*current_x);
        *current_y = *current_y - 97;
        *current_x = 8 - *current_x;
        if (*current_x >= 0 && *current_x <= 7 && *current_y >= 0 && *current_y <= 7) {
            if (player == 1)
                if (strchr("PRNBQK", board[*current_x][*current_y])) {
                    return board[*current_x][*current_y];
                    flag = 0;
                }
            if (player == 2)
                if (strchr("prnbqk", board[*current_x][*current_y])) {
                    return board[*current_x][*current_y];
                    flag = 0;
                }
        }
        else
            printf("Wrong\n"); //need fix
    }
}

void moveInput(int *to_x, char *to_y) {
    int flag = 1;
    while (flag) {
        scanf("%c %d", &*to_y, &*to_x);
        *to_y = *to_y - 97;
        *to_x = 8 - *to_x;
        if (*to_x >= 0 && *to_x <= 7 && *to_y >= 0 && *to_y <= 7)
            flag = 0;
        else
            printf("Wrong\n");  //need fix
    }
}