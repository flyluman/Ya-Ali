#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10001

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int *list, int n) {

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(list[i] > list[j]) {
                swap(list + i, list + j);
            }
        }
    }

    return;
}

void counting_sort(int *list, int n) {
    int *counter = (int *) calloc(sizeof(int) , MAX);

    for(int i=0; i<n; i++) {
        counter[list[i]] += 1;
    }

    int k = 0;

    for(int i=0; i<MAX; i++) {
        if(counter[i]) {
            while(counter[i]--) {
                list[k++] = i;
            }
        }
    }

    free(counter);
    return;
}

int main() {

    clock_t clk;
    int n, *list_b, *list_c;

    FILE *in = fopen("input.txt", "r");
    fscanf(in, "%d", &n);

    list_b = (int *) malloc(sizeof(int) * n);
    list_c = (int *) malloc(sizeof(int) * n);

    for(int i=0; i<n; i++) {
        fscanf(in, "%d", list_b + i);
        list_c[i] = list_b[i];
    }

    clk = clock();

    bubble_sort(list_b, n);

    clk = clock() - clk;
    printf("Time eclapsed for bubble sort  when  n = %d => %0.4lf ms\n", n, clk * 1000.0 / CLOCKS_PER_SEC);

    
    clk = clock();

    counting_sort(list_c, n);

    clk = clock() - clk;
    printf("Time eclapsed for counting sort when n = %d => %0.4lf ms\n", n, clk * 1000.0 / CLOCKS_PER_SEC);

    fclose(in);
    free(list_b);
    free(list_c);
    return 0;
}