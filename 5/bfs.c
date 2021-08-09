#include <stdio.h>
#include <stdlib.h>

int n;

int *bfs(int v, int (*matrix)[n]) {
    int *queue = (int *) calloc(sizeof(int), n);
    int *visited = (int *) calloc(sizeof(int), n);

    queue[0] = v;
    int fr = 0, bk = 0;

    while(fr <= bk) {
        for(int i=0; i<n; i++) {
            if(matrix[queue[fr]][i] && !visited[i]) {
                queue[++bk] = i;
            }
        }
        visited[queue[fr++]] = 1;
    }

    visited[v] = 0;
    free(queue);
    return visited;
}

int main() {

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int (*matrix)[n] = (int (*)[n]) malloc(sizeof(int) * n * n);

    printf("Enter graph data in matrix form: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int v;
    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    int *visited = bfs(v-1, matrix);

    printf("\nThe node which are reachable are: ");
    for(int i=0; i<n; i++) {
        if(visited[i]) {
            printf("%d ", i+1);
        }
    }
    printf("\n");

    free(matrix);
    free(visited);
    return 0;
}