#include"header.h"
void paw_move(int player, int current_x, int current_y,
                 int to_x, int to_y, char board[8][8][5],
                char kill_white[16][5],char kill_black[16][5],
                int *count_deadWhite,int *count_deadBlack,bool *flag, int moves, int killed_white_at[16], int killed_black_at[16], 
                int *flagpassant, int *passant_x, int *passant_y, int passant_counter[8], int *passantIndex, int promotion_white_at[8], 
                char promotion_white_type[8][5], int *WPromotionIndex,int promotion_black_at[8],
                 char promotion_black_type[8][5], int *BPromotionIndex, int *moves_draw, int *flagsave, int *promotion_index, int promotion_hist[]){
                    *flag = false;
                    if(player ==1){
                        if(to_x==current_x-2 && to_y==current_y){
                            if(current_x==6){
                                if((!check_black(to_x,to_y,board))&&(!check_white(to_x,to_y,board))){
                                    if((!check_black(to_x+1,to_y,board))&&(!check_white(to_x+1,to_y,board))){
                                    Checkpassant(to_x, to_y, passant_x, passant_y, player, flagpassant,board);
                                    *flag=true;
                                    }
                                }
                            }
                        }else if(to_x==current_x-1 && to_y==current_y){
                            if((!check_black(to_x,to_y,board))&&(!check_white(to_x,to_y,board))){
                                *flag=true;
                            }
                        }else if(to_x==current_x-1 && (to_y==current_y+1 || to_y==current_y-1)){
                            if(check_black(to_x,to_y,board) || *flagpassant == 1){
                                if ((*flagpassant == 1) && (to_x == *passant_x) && (to_y == *passant_y)) Dopassant(current_x, current_y, to_x, to_y, player, moves, flag, count_deadBlack, 
                                                                count_deadWhite, kill_black, killed_black_at, kill_white, killed_white_at, board, passant_x, passant_y, passant_counter, passantIndex);
                                else {
                                    strcpy(kill_black[(*count_deadBlack)++] , board[to_x][to_y]);
                                    killed_black_at[*count_deadBlack-1] = moves;
                                    *flag=true;
                                }
                            }
                        }
                    }
                    if(player ==2){
                        if(to_x==current_x+2 && to_y==current_y){
                            if(current_x==1){
                                if((!check_black(to_x,to_y,board))&&(!check_white(to_x,to_y,board))){
                                    if((!check_black(to_x-1,to_y,board))&&(!check_white(to_x-1,to_y,board))){
                                    Checkpassant(to_x, to_y, passant_x, passant_y, player, flagpassant,board);
                                    *flag=true;
                                    }
                                }
                            }
                        }else if(to_x==current_x+1 && to_y==current_y){
                            if(!check_black(to_x,to_y,board)&&!check_white(to_x,to_y,board)){
                                *flag=true;
                            }
                        }else if(to_x==current_x+1 && (to_y==current_y+1 || to_y==current_y-1)){
                            if(check_white(to_x,to_y,board) || *flagpassant == 1){
                                if (((*flagpassant) == 1) && (to_x == *passant_x) && (to_y == *passant_y)) {Dopassant(current_x, current_y, to_x, to_y, player, moves, flag, count_deadBlack, 
                                                                count_deadWhite, kill_black, killed_black_at, kill_white, killed_white_at, board, passant_x, passant_y, passant_counter, passantIndex);}
                                else {
                                    strcpy(kill_white[(*count_deadWhite)++] , board[to_x][to_y]);
                                    killed_white_at[*count_deadWhite-1] = moves;
                                    *flag=true;
                                }
                            }
                        }
                    }
            if(*flag){
            *moves_draw = 0;
            strcpy(board[to_x][to_y] , board[current_x][current_y]);
            FixBoard(current_x,current_y,board);
                char black[6][5]={"♖", "♘", "♗", "♕"};
                char white[6][5]={"♜", "♞", "♝", "♛"};
                int ans;
                if(player==1){
                    if(to_x==0){
                        printf("get pormotion!\nchoose from the list:\n");
                        for(int i=0;i<4;i++){
                            printf("%d ---> %s\n",i+1,white[i]);
                        }
                        if (*flagsave == 1) {
                            ans = promotion_hist[(*promotion_index)++];
                        }
                        else scanf("%d",&ans);
                        while(ans<1 || ans>4) {
                        printf("WRONG INPUT\n");
                        while (getchar() != '\n');
                        scanf("%d",&ans);
                        }
                        strcpy(board[to_x][to_y] , white[ans-1]);
                        promotion_white_at[*WPromotionIndex] = moves;
                        if (*flagsave == 0 ) promotion_hist[(*promotion_index)++] = ans;
                        strcpy(promotion_white_type[(*WPromotionIndex)++], white[ans-1]);
                    }
                }if(player==2){
                    if(to_x==7){
                        printf("get pormotion!\nchoose from the list:\n");
                        for(int i=0;i<4;i++){
                            printf("%d ---> %s\n",i+1,black[i]);
                        }
                        if (*flagsave == 1) {
                            ans = promotion_hist[(*promotion_index)++];
                        }
                        else scanf("%d",&ans);
                        while(ans<1 || ans>4) {
                        printf("WRONG INPUT\n");
                        while (getchar() != '\n');
                        scanf("%d",&ans);
                        }
                        strcpy(board[to_x][to_y] , black[ans-1]);
                        promotion_black_at[*BPromotionIndex] = moves;
                        if (*flagsave == 0) promotion_hist[(*promotion_index)++] = ans;
                        strcpy(promotion_black_type[(*BPromotionIndex)++], black[ans-1]);
                    }
                }
            }
    }