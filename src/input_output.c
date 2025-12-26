#include"header.h"
void Input(int player, 
    int *current_x, char *current_y,
    int *to_x, char *to_y, 
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
            if (*to_x >= 0 && *to_x <= 7 && *to_y >= 0 && *to_y <= 7) {
                if (player == 1){
                    if (check_white(*current_x,*current_y,board)) {
                        if (!check_white(*to_x,*to_y,board)) {
                            flag = false;
                        }else printf("Wrong move!\n");
                    }else printf("Wrong move!\n");}
                if (player == 2){
                    if (check_black(*current_x,*current_y,board)) {
                        if (!check_black(*to_x,*to_y,board)) {
                            flag = false;
                        }else printf("Wrong move!\n");
                    }else printf("Wrong move!\n");}
            } else printf("out of board!\n");
        }else printf("out of baord!\n");
    }
}