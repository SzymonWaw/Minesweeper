#ifndef BOARD_H
#define BOARD_H


#define BOARD_SIZE 10
#define MINE_COUNT 15


typedef struct {
    int is_mine;
    int is_revealed;
    int is_flagged;
    int mine_count;
} Field;


void init_board(Field board[BOARD_SIZE][BOARD_SIZE]);

void place_mines(Field board[BOARD_SIZE][BOARD_SIZE]);

void calculate_neighbors(Field board[BOARD_SIZE][BOARD_SIZE]);


int reveal_field(Field board[BOARD_SIZE][BOARD_SIZE], int x, int y);

int check_win(Field board[BOARD_SIZE][BOARD_SIZE]);


int is_inside(int x, int y);

#endif // BOARD_H