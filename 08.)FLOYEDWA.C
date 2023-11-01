#include <stdio.h>
#include <limits.h>
#include<conio.h>

// Maximum number of vertices
#define V 100
#define INT_MAX 9999


int counter = 0;

// Function to print the solution matrix
void printSolution(int dist[V][V], int n) {
    int i,j;
    printf("Shortest distances between every pair of vertices:\n");
    for ( i = 0; i < n; i++) {
	for ( j = 0; j < n; j++) {
	    if (dist[i][j] == INT_MAX) {
		printf("INF ");
	    } else {
		printf("%d   ", dist[i][j]);
	    }
	}
	printf("\n");
    }
}

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(int graph[V][V], int n) {
    int dist[V][V];
    int i,j,k;

    // Initialize the dist matrix to be the same as the input graph matrix
    for ( i = 0; i < n; i++) {
	for ( j = 0; j < n; j++) {
	    dist[i][j] = graph[i][j];
	}
    }

    // Update dist[][] if a shorter path is found
    for ( k = 0; k < n; k++) {
	for ( i = 0; i < n; i++) {
	    for ( j = 0; j < n; j++) {
		counter++;
		if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
		    dist[i][j] = dist[i][k] + dist[k][j];
		}
	    }
	}
    }

    // Print the resulting matrix
    printSolution(dist, n);
}

int main() {

    int i,j,n;
    int graph[V][V];

    clrscr();

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the graph matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
	for ( j = 0; j < n; j++) {
	    scanf("%d", &graph[i][j]);
	}
    }

    floydWarshall(graph, n);

    printf("Time Complexity = %d", counter);

    getch();
    return 0;
}