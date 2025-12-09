void draw(char board[8][8][32],char kill_white[8][32],char kill_black[8][32]);
void Input(int player, int *current_x, char *current_y, char board[8][8]);
void FixBoard(int current_x, int current_y,char board[8][8]);
void PowMove(int player, int current_x, int current_y, int to_x, int to_y, char board[8][8]);