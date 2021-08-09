#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return -1;
    }

    time_t t;
    srand((unsigned)time(&t));

    int n = atoi(argv[1]);

    FILE *out = fopen("input.txt", "w");

    if (!out) {
        printf("Couldn't create input.txt\nPlease check memory status of your OS.\n");
        return -1;
    }

    fprintf(out, "%d\n", n);

    for (int i = 0; i < n; i++) {
        fprintf(out, "%d\n", rand() % 10001);
    }

    fclose(out);

    return 0;
}
