
#include <stdio.h>
#include<conio.h>

void fractionalKnapsack(int n, int V[], int W[], int M) {
    int selected[100];
    int i,j;
    int sw = 0;      // Weight of selected items
    double sp = 0.0;      // Profit of selected items
    int counter=0;
    int tempWeight,tempProfit;
    // Calculate profit-to-weight ratio (pi/wi) for each item
    double ratios[100];
    for ( i = 0; i < n; i++) {
	ratios[i] = (double)V[i] / W[i];
	counter++;
    }

    // Sort items in descending order of profit-to-weight ratio
    for ( i = 0; i< n - 1; i++) {
	for( j = i + 1; j < n; j++) {
	    counter++;
	    if (ratios[i] < ratios[j]) {
		// Swap ratios
		double tempRatio = ratios[i];
		ratios[i] = ratios[j];
		ratios[j] = tempRatio;

		// Swap weights
		tempWeight = W[i];
		W[i] = W[j];
		W[j] = tempWeight;

		// Swap profits
		tempProfit = V[i];
		V[i] = V[j];
		V[j] = tempProfit;
	    }
	}
    }
for( i=0;i<n;i++) {
    if (sw + W[i] <= M) {
	selected[i] = 1;
	sw = sw + W[i];
	sp = sp + V[i];
    }
else {
	double frac = (double)(M - sw) / W[i];
	selected[i] = frac; // Select a fraction of item i
	sw = M; // Knapsack is full
	sp = sp + (V[i] * frac);
    }
    counter++;
}
    printf("Total Weight: %d\n", sw);
    printf("Total Profit: %lf\n", sp);
    printf("Time Complexity: %d",counter);
}

int main() {
    int i,n, M;
    int V[100]; // Array of profits
    int W[100]; // Array of weights
    clrscr();

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the profits of each item:\n");
    for ( i = 0; i < n; i++) {
	scanf("%d", &V[i]);
    }
    printf("Enter the weight of each item:\n");
    for ( i = 0; i < n; i++) {
	scanf("%d", &W[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &M);

    fractionalKnapsack(n, V, W, M);

    getch();
    return 0;
}
