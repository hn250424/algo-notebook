// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

#include <stdio.h>
#include <string.h>

int row[9][10] = {0};
int col[9][10] = {0};
int subgrid[9][10] = {0};

// For Checking.
void printBoard(char** board) {
    printf("======================================================\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void insert(char** board, int r, int c, int v) {
    row[r][v] = 1;
    col[c][v] = 1;
    subgrid[(c / 3) + ((r / 3) * 3)][v] = 1;
    board[r][c] = v + '0';
}

void delete(char** board, int r, int c, int v) {
    row[r][v] = 0;
    col[c][v] = 0;
    subgrid[(c / 3) + ((r / 3) * 3)][v] = 0;
    board[r][c] = '.';
}

int validate(char** board, int r, int c, int v) {
    if (
        (row[r][v] == 1) ||
        (col[c][v] == 1) ||
        (subgrid[(c / 3) + ((r / 3) * 3)][v] == 1)
    ) {
        return 0;
    } else {
        return 1;
    }
}

int backtrack(char** board, int r, int c) {
    if (r == 9) return 1;

    int nr = (c == 8) ? r + 1 : r;
    int nc = (c + 1) % 9;

    if (board[r][c] != '.') return backtrack(board, nr, nc);
    
     for (int v = 1; v <= 9; v++) {
        if (validate(board, r, c, v)) {
            insert(board, r, c, v);
            if (backtrack(board, nr, nc)) return 1;
            delete(board, r, c, v);
        }
    }

    return 0;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    // For submit at LeetCode.
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(subgrid, 0, sizeof(subgrid));

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] != '.') {
                row[i][board[i][j] - '0'] = 1;
                col[j][board[i][j] - '0'] = 1;
                subgrid[(j / 3) + ((i / 3) * 3)][board[i][j] - '0'] = 1;
            } 
        }
    }

    backtrack(board, 0, 0);
}

int main() {
    // g.
    char _board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    char* board[9];
    for (int i = 0; i < 9; i++) {
        board[i] = _board[i];
    }
    int boardSize = 9;
    int boardColSize[9] = {9,9,9,9,9,9,9,9,9};

    printBoard(board);
    solveSudoku(board, boardSize, boardColSize);
    printBoard(board);

    return 0;
}

/**
 * Runtime: 93ms 62.53%
 * Memory: 8.61MB 25.06%
 */