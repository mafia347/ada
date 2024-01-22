#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10

int n;
int board[MAX_N][MAX_N];

// Function to print the board
void printBoard() {
    printf("Patient Allotment:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a patient can be placed at board[row][col]
bool isSafe(int row, int col) {
    // Check in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Recursive function to solve the patient allotment problem
bool solveNQueens(int col) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    printf("Enter the number of patients (rooms): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_N) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    if (solveNQueens(0)) {
        printBoard();
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}