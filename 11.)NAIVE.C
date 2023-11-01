#include <stdio.h>
#include <string.h>
#include <conio.h>

int counter=0;


int naiveStringMatcher(const char *T, const char *P) {
    int n = strlen(T);
    int m = strlen(P);
    int s;
    for ( s = 0; s <= n - m; s++) {
        counter++;
	int j = 0;

	while (j < m && T[s + j] == P[j]) {
	      counter++;
	    j++;
	}

	if (j == m) {
	    return s;  // valid shift found
	}
    }

    return -1;  // no valid shift exists
}

int main() {
    char T[100];  // Define a buffer for user input
    char P[100];  // Define a buffer for user input
    int result;
    clrscr();
    printf("Enter the text: ");
    gets(T);  // Read the text from user input

    printf("Enter the pattern: ");
    gets(P);  // Read the pattern from user input

    // Remove the newline character from the input
    T[strcspn(T, "\n")] = '\0';
    P[strcspn(P, "\n")] = '\0';

    result = naiveStringMatcher(T, P);

    if (result != -1) {
	printf("Pattern found at index %d\n", result);
    } else {
	printf("Pattern not found in the text.\n");
    }
printf("Time Complexity:- %d",counter);
    getch();
    return 0;
}
