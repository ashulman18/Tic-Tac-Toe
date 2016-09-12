#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


struct tttboard_t {
    int tiles[3][3];
};

struct tttboard_t *ttt_board_create(void) {
    struct tttboard_t *board = malloc(sizeof(struct tttboard_t));
    bzero(board,sizeof(struct tttboard_t));
    return board;
}

void ttt_place_piece(struct tttboard_t *board, int color, int x, int y) {
    if (color == 0)
        board->tiles[x][y] = -1;
    else if (color == 1)
        board->tiles[x][y] = 1;
}

int winner(struct tttboard_t *board)
{
    int count11 = 0; // -1
    int count1 = 0;
    int count11c = 0; // -1
    int count1c = 0;
    int result = 0;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board->tiles[i][j] == -1){
                count11++;
                if(count11 == 3)
                    result = -1;
            }
            if (board->tiles[i][j] == 1){
                count1++;
                if(count1 == 3)
                    result = 1;
            }
            if (board->tiles[j][i] == -1){
                count11c++;
                if(count11c == 3)
                    result = -1;
            }
            if (board->tiles[j][i] == 1){
                count1c++;
                if(count1c == 3)
                    result = 1;
            }
        }
        count11 = 0;
        count1 = 0;
        count11c = 0;
        count1c = 0;
    }
    
    if ((board->tiles[0][0] == -1 && board->tiles[1][1] == -1 && board->tiles[2][2] == -1) || (board->tiles[0][2] == -1 && board->tiles[1][1] == -1 && board->tiles[2][0] == -1))
        result = -1;
    else if((board->tiles[0][0] == 1 && board->tiles[1][1] == 1 && board->tiles[2][2] == 1) || (board->tiles[0][2] == 1 && board->tiles[1][1] == 1 && board->tiles[2][0] == 1))
        result = 1;
    
    return result;
    
}

int main(int argc, char **argv) {
    
    struct tttboard_t *board = ttt_board_create();
    
    ttt_place_piece(board, 0, 0, 0);
    //ttt_place_piece(board, 1, 0, 0);
    ttt_place_piece(board, 1, 1, 0);
    ttt_place_piece(board, 0, 1, 1);
    ttt_place_piece(board, 1, 2, 0);
    ttt_place_piece(board, 0, 2, 2);
    
    printf("%i", winner(board));
    
    return 0;
}