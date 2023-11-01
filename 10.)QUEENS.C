#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int board[20], count = 0;
int counter=0;


int place(int row, int column) {
    int i;
    for (i = 1; i <= row - 1; ++i) {
        // Check for column conflict or diagonal conflict
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void print_board(int n) {
    int i, j;
    printf("\nSolution %d:\n", ++count);

    for (i = 1; i <= n; ++i){
        counter++;
    
        printf("\t%d", i);
}
    for (i = 1; i <= n; ++i) {
        counter++;
        printf("\n%d", i);
       
        for (j = 1; j <= n; ++j) { 
            if (board[i] == j)
                printf("\tQ"); // Queen at this position
            else
                printf("\t-"); // Empty slot
        }
    }
    printf("\n");
}

void Queen(int row, int n) {
    int column;
    for (column = 1; column <= n; ++column) { 
        if (place(row, column)) {
            board[row] = column;
            if (row == n)
                print_board(n);
            else
                Queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    clrscr();
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Invalid input. Please enter a positive integer less than or equal to 20.\n");
        return 1;
    }
    
    Queen(1, n);

    if (count == 0)
        printf("No solutions found for %d queens.\n", n);
        
 printf("Time Complexity:- %d \n", counter);
getch();
return 0;
}