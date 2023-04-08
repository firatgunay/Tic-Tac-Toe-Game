#include <stdio.h>

char board[3][3];


void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    int i, j;
    printf("    0 1 2\n");
    for (i = 0; i < 3; i++) {
        printf("%d   ", i);
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void set_mark(int row, int col, char mark) {
    board[row][col] = mark;
}

int is_valid_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    if (board[row][col] != '-') {
        return 0;
    }
    return 1;
}

int game_over() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1;
        }
    }

    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }

    return 2;
}


void play_game() {
    int row, col, player = 1, game_status;
    char mark;
    initialize_board();
    do {
        print_board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, please enter row and column for your mark: ", player);
        scanf("%d %d", &row, &col);
        if (!is_valid_move(row, col)) {
            printf("Invalid move! Please try again.\n");
            continue;
        }
        mark = (player == 1) ? 'X' : 'O';
        set_mark(row, col, mark);
        game_status = game_over();
        player++;
    } while (game_status == 0);
    print_board();
    if (game_status == 1) {
        printf("Congratulations, Player %d won!\n", --player);
    } else {
        printf("It's a draw!\n");
    }
}
int main() {
    play_game();
    return 0;
}



