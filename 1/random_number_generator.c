#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    time_t t;
    srand((unsigned)time(&t));

    int n = 20000;

    char file_name[25];

    for(int i=0; i<3; i++) {

        sprintf(file_name, "quick%d.txt", i+1);
        FILE *out = fopen(file_name, "w");

        if (!out)
        {
            printf("Couldn't create %s\nPlease check memory status of your OS.\n", file_name);
            return -1;
        }

        fprintf(out, "%d\n", n);
        for (int j = 0; j < n; j++) {
            fprintf(out, "%d\n", rand());
        }

        n *= 10;
        fclose(out);
    }

    return 0;
}
