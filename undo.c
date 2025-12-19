#include"header.h"

void Undo(int *current_x, char *current_y, int *to_x, char *to_y, int moves,char savegame[]) {
        *current_x = 8 - (savegame[moves--]-48);
        *current_y = savegame[moves--]-97;
        *to_x = 8 - (savegame[moves--]-48);
        *to_y = savegame[moves--]-97;
}