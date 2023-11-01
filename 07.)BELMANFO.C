#include <stdio.h>
#include <limits.h>
#include <conio.h>

#define MAX_VERTICES 100
#define INF INT_MAX
int counter=0;
int graph[MAX_VERTICES][MAX_VERTICES];
int V;

void BellmanFord(int src)
 {
    int i, v ,u,count;
    int dist[MAX_VERTICES];

    // Initialize distances from source to all other vertices as INF
    for ( i = 1; i <= V; i++)
	dist[i] = INF;
    dist[src] = 0;

    // Relax edges V-1 times
    for ( count = 1; count <= V - 1; count++) {
	for ( u = 1; u <= V; u++) {
	    counter++;
	    for (v = 1; v <= V; v++) {
		if (graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
		    dist[v] = dist[u] + graph[u][v];
	    }
	}
    }

    // Print the shortest distances
    printf("Vertex   Distance from Source\n");
    for ( i = 1; i <= V; i++) {
	if (dist[i] == INF) {
	    printf("%d \t\t INFINITY\n", i);
	} else {
	    printf("%d \t\t %d\n", i, dist[i]);
	}
    }
}

int main()
 {
    int i,j,source;

    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for ( i = 1; i <= V; i++) {
	for ( j = 1; j <= V; j++) {
	    scanf("%d", &graph[i][j]);
	}
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    BellmanFord(source);

    printf("Time Complexity = %d",counter);

    getch();
    return 0;
}