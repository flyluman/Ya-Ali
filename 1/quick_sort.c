#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int *list, int start_i, int end_i) {

    int pvt = list[end_i], pvt_i = start_i;
    
    for(int i=start_i; i<end_i; i++) {
        if(list[i] <= pvt) {
            swap(list + i, list + pvt_i);
            pvt_i += 1;
        }
    }
    swap(list + pvt_i, list + end_i);
    return pvt_i;
}

void quick_sort(int *list, int start_i, int end_i) {

    if(start_i < end_i) {
        int partition_i = partition(list, start_i, end_i);
        quick_sort(list, start_i, partition_i - 1);
        quick_sort(list, partition_i + 1, end_i);
    } else {
        return;
    } 
}

int main() {

    FILE *in;
    clock_t clk;
    int n, *list;
    char file_name[25];

    for(int i=0; i<3; i++) {

        sprintf(file_name, "quick%d.txt", i+1);
        in = fopen(file_name, "r");

        if (!in) {
            printf("%s file not found.\nPlease compile & run \"random_number_generator\" first.\n", file_name);
            return -1;
        }

        fscanf(in, "%d", &n);
        list = (int *) malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++) {
            fscanf(in, "%d", list+j);
        }

        clk = clock();
        quick_sort(list, 0, n-1);
        clk = clock() - clk;
        printf("Time eclapsed when n = %-7d => %0.4lf ms\n", n, clk * 1000.0 / CLOCKS_PER_SEC);

        free(list);
        fclose(in);
    }

    return 0;
}
