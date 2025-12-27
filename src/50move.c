#include "header.h"

void Checkdraw50(int count_deadWhite, int count_deadBlack, int *white_draw, int *black_draw, int *moves_draw, int *flagdraw50, int flagsave, int *draw_hist) {
    int draw;

    if ( (count_deadWhite != *white_draw) || (count_deadBlack != *black_draw) ) {
        *moves_draw = 0;
        *white_draw = count_deadWhite;
        *black_draw = count_deadBlack;
        *flagdraw50 = 1;
        return;
    }

    if (*moves_draw == 50) {
        while (true) {
        if (flagsave == 1) draw = *draw_hist;
        else {
            printf("DO YOU WANT TO DRAW (1/0)?:");
            scanf(" %d",&draw);
        }
        if (draw == 1 || draw == 0) break;
        while (getchar() != '\n');
        }
        if (flagsave == 0) *draw_hist = draw;
        if (draw == 0) *flagdraw50 = 1;
        if (draw == 1) {
            printf("GAME ENDED DRAW\n");
            *flagdraw50 = 0;
        }
    }
    if (*moves_draw == 75) {
        printf("GAME ENDED DRAW\n:");
        *flagdraw50 = 0;
    }
}