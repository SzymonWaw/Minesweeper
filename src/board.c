#include "board.h"
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 10
#define MINE_COUNT 15

void init_board(Field board[BOARD_SIZE][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].is_mine = 0;
            board[i][j].is_revealed = 0;
            board[i][j].is_flagged = 0;
            board[i][j].mine_count = 0;
        }
    }
}

void place_mines(Field board[BOARD_SIZE][BOARD_SIZE]) {
    int placed = 0;
    
    while (placed < MINE_COUNT) {
        int r = rand() % BOARD_SIZE;
        int c = rand() % BOARD_SIZE;

        if (board[r][c].is_mine == 0) {
            board[r][c].is_mine = 1;
            placed++;
        }
    }
}


/*
typedef struct {
    int is_mine;      // 1 jeśli mina, 0 jeśli bezpieczne
    int is_revealed;  // 1 jeśli odkryte, 0 jeśli zakryte
    int is_flagged;   // 1 jeśli gracz postawił flagę
    int mine_count;   // Liczba min w sąsiedztwie (0-8)
} Field;
*/

void calculate_neighbors(Field board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            
            if (board[i][j].is_mine == 0){


                int count = 0;

                for (int k = i - 1; k <= i + 1; k++) {
                    for (int m = j - 1; m <= j + 1; m++) {
                        if (k >= 0 && k < BOARD_SIZE && m >= 0 && m < BOARD_SIZE) {
                            if (board[k][m].is_mine) {
                                count++;
                            }
                        }
                    
                    }
                }
                board[i][j].mine_count = count;
            }
        }
    }
}

int reveal_field(Field board[BOARD_SIZE][BOARD_SIZE], int x, int y){
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) return 0;
    if (board[x][y].is_revealed) return 0;
    board[x][y].is_revealed = 1;
    if(board[x][y].is_mine = 1) return 1;

    if(board[x][y].mine_count == 0){
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                reveal_field(board, i, j);
            }
        }
    }

    return 0;
}

int check_win(Field board[BOARD_SIZE][BOARD_SIZE]){
    
    int unreavled_safe_fields = 0;
    
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].is_mine == 0 && board[i][j].is_revealed == 0){
                unreavled_safe_fields++;
            }
        }
    }

    if(unreavled_safe_fields == 0) return 1;
    
    return 0;
}

int is_inside(int x, int y){

}