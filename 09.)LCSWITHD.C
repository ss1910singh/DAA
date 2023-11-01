#include <stdio.h>
#include <string.h>
#include <conio.h>
                                       
int i, j, m, n, LCS_table[50][50];
char S1[50], S2[50], b[50][50];
int counter = 0;

void printTable() {
  printf("\nDynamic Programming Table:\n");
  printf("         ");
  for (i = 0; i < m; i++) {
    printf("%c   ", S1[i]);
  }
  printf("\n");

  for (i = 0; i <= n; i++) {
    if (i > 0) {
      printf("%c ", S2[i - 1]);
    } else {
      printf("  ");
    }
    for (j = 0; j <= m; j++) {
    
        if (i > 0 && j > 0 && S2[i - 1] == S1[j - 1]) {
          printf("  \\"); // Diagonal arrow for matches
        } else {
          printf("   "); // Empty space for non-matches
        }
        printf("%d", LCS_table[i][j]); // Just the value
      
    }
    printf("\n");
  }
}

void lcsAlgo() {
  int index;
  char lcsAlgo[50];

  printf("Enter the first string (S1): ");
  scanf("%s", S1);

  printf("Enter the second string (S2): ");
  scanf("%s", S2);

  m = strlen(S1);
  n = strlen(S2);

  // Filling 0's in the matrix
  for (i = 0; i <= n; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= m; i++)
    LCS_table[0][i] = 0;

  // Building the matrix in a bottom-up way
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      counter++;
      if (S2[i - 1] == S1[j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
      } else {
        LCS_table[i][j] = LCS_table[i][j - 1];
      }
    }
  }

  // Print the table with strings at the top
  printTable();

  index = LCS_table[n][m];
  lcsAlgo[index] = '\0';

  i = n;
  j = m;

  while (i > 0 && j > 0) {
    if (S2[i - 1] == S1[j - 1]) {
      lcsAlgo[index - 1] = S2[i - 1];
      i--;
      j--;
      index--;
    } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  // Printing the subsequences
  printf("\nS1: %s\nS2: %s\n", S1, S2);
  printf("LCS: %s\n", lcsAlgo);
}

int main() {     
  clrscr();
  lcsAlgo();
  printf("Time Complexity: %d\n", counter);
  getch();
  return 0;
}