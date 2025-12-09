#include <stdlib.h>
#include <string.h>
#include <header.h>

void PowMove(int player, int current_x, int current_y, int to_x, int to_y, char board[8][8][32]) {
    int flag = 1;
    if (player == 1) { //(white)
        if (current_x == 6 && to_x == 4 && strchr("._", board[current_x - 2][current_y]))
            flag = 0; // move two steps
        else if (to_x == current_x - 1 && to_y == current_y && strchr("._", board[current_x - 1][current_y]))
            flag = 0; // move one step
        else if (strchr("prnbqk", board[to_x][to_y]) && to_x == current_x - 1 && abs(current_y - to_y) == 1) { // eat diagonally
            // kill_black[index] = board[to_x][to_y];
            flag = 0;
        }
    }
    if (player == 2) { //(black)
        if (current_x == 1 && to_x == 3 && (board[current_x + 2][current_y] == '_' || board[current_x + 2][current_y] == '.'))
            flag = 0; // same code just change - to + !?
        else if (to_x == current_x + 1 && to_y == current_y && (board[current_x + 1][current_y] == '_' || board[current_x + 1][current_y] == '.'))
            flag = 0;
        else if (strchr("PRNBQK", board[to_x][to_y]) && to_x == current_x + 1 && abs(current_y - to_y) == 1) { // eat diagonally
            // kill_white[index] = board[to_x][to_y];
            flag = 0;
        }
    }
    if (!flag) {
        if (to_x == 0 || to_x == 7)
            board[to_x][to_y] = Promotion(to_x);
        if (player % 2 == 1)
            board[to_x][to_y] = 'P';
        else
            board[to_x][to_y] = 'p';
        FixBoard(current_x, current_y, board);
    }
}

void BishopMove(int player, int current_x, char current_y, int to_x, char to_y, char board[8][8]) {
    int flag = 1, m = to_x, w = to_y; // m,w is a flag that will be used as index moving in the array (i,j)
    if (current_x == to_x || current_y == to_y)
        return 0;
    for (int i = 0; i <= 7; i++) { // I need to loop depend on how many rows I will be moving so it will never be more than 7
        if ((current_x - current_y == abs(to_x - to_y)) || (abs(abs(to_x - to_y) - 2 * i)) == abs(current_x - current_y)){ // from left to right all difference is same and from right to left difference is increasing by 2
            while (flag) {
                while (m != current_x) {
                    if (board[m][abs(w)] == '_' || board[m][abs(w)] == '.') { // check from the new position to the current possition if it's empty (valid move)
                        if (to_x > current_x)
                            m--;
                        else if (to_x < current_x)
                            m++;
                        if (to_y > current_y)
                            w--;
                        else if (to_y < current_y)
                            w++;
                    }
                    else
                        flag = 0;
                }
                if (m == current_x && w == current_y) { // using if(flag) will validate the move even if he didn't enter the loop
                    if (player == 1)
                        board[to_x][to_y] = 'B';
                    if (player == 2)
                        board[to_x][to_y] = 'b';
                    FixBoard(current_x, current_y, board);
                    flag = 0;
                }
                else
                    flag = 0;
            }
        }
    }
}

void RookMove(int current_x, int current_y, int to_x, int to_y, int board[8][8]) {
    int flag = 1, m;
    if (to_x == current_x && to_y != current_y) { // moving horizontal
        m = to_y;
        while (m != current_y) {
            if (board[current_x][m] == '_' || board[current_x][m] == '.') {
                if (to_y > current_y)
                    m--;
                else if (to_y < current_y)
                    m++;
            }
            else
                flag = 0;
        }
        if (flag)
            printf("VALID\n");
    }
    if (to_y == current_y && to_x != current_x) { // moving vertical
        m = to_x;
        while (m != current_x) {
            if (board[m][current_y] == '_' || board[m][current_y] == '.') {
                if (to_x > current_x)
                    m--;
                else if (to_x < current_x)
                    m++;
            }
            else
                flag = 0;
        }
        if (flag)
            printf("VALID\n");
    }
}