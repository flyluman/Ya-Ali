#include <stdio.h>
#include <stdlib.h>

int it, n, sl, *col, *rlt, *diag1, *diag2;

void search(int y) {

    if (y == n) {
        printf("Solution #%d:\n", ++sl);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(rlt[i] == j) {
                    printf("Q\t");
                } else {
                    printf("*\t");
                }
            }
            printf("\n");
        }

        printf("Number of iteration: %d\n\n", it);
        it = 0;

        return;
    }

    it += 1;

    for (int x = 0; x < n; x++) {

        if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;

        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        rlt[y] = x;

        search(y + 1);

        col[x] = diag1[x + y] = diag2[x - y + n - 1] = rlt[y] = 0;
    }
    
    return;
}

int main() {

    FILE *in = fopen("queen.txt", "r");

    if(!in) {
        printf("queen.txt file not found.\n");
        return -1;
    }
    
    fscanf(in, "%d", &n);

    col = (int *)calloc(sizeof(int), n);
    rlt = (int *)calloc(sizeof(int), n);
    diag1 = (int *)calloc(sizeof(int), 2 * n - 1);
    diag2 = (int *)calloc(sizeof(int), 2 * n - 1);

    search(0);

    free(col);
    free(rlt);
    free(diag1);
    free(diag2);

    fclose(in);
    return 0;
}
