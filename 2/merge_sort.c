#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *list, int start_i, int mid_i, int end_i) {

    int n_list_l = mid_i - start_i + 1, n_list_r = end_i - mid_i;
    
    int *list_l = (int *) malloc(sizeof(int) * n_list_l);
    int *list_r = (int *) malloc(sizeof(int) * n_list_r);

    for(int i=0; i<n_list_l; i++) {
        list_l[i] = list[start_i + i];
    }

    for(int i=0; i<n_list_r; i++) {
        list_r[i] = list[mid_i + i + 1];
    }

    int i=0, j=0, k=start_i;

    while(i < n_list_l && j < n_list_r) {
        if(list_l[i] <= list_r[j]) {
            list[k++] = list_l[i++];
        } else {
            list[k++] = list_r[j++];
        }
    }

    while(i < n_list_l) {
        list[k++] = list_l[i++];
    }

    while(i < n_list_r) {
        list[k++] = list_r[j++];
    }

    free(list_l);
    free(list_r);
    return;
}

void merge_sort(int *list, int start_i, int end_i) {

    if(start_i < end_i) {
        int mid_i = start_i + (end_i - start_i) / 2;
        merge_sort(list, start_i, mid_i);
        merge_sort(list, mid_i+1, end_i);
        merge(list, start_i, mid_i, end_i);
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

        sprintf(file_name, "../1/quick%d.txt", i+1);
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
        merge_sort(list, 0, n-1);
        clk = clock() - clk;
        printf("Time eclapsed when n = %-7d => %0.4lf ms\n", n, clk * 1000.0 / CLOCKS_PER_SEC);
        
        free(list);
        fclose(in);
    }

    return 0;
}
