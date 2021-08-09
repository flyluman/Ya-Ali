## INFO

#### quick[1-3].txt:

contains the value of n followed by n integers.

#### random_number_generator.c:

will create 3 file quick1.txt, quick2.txt, quick3.txt

#### quick_sort.c:

will one by one input generated files, sort using quick sort & output required time for each file in ms.

#### Compile & Run:

Use [GCC](https://gcc.gnu.org/) to compile random_number_generator.c & quick_sort.c

```bash
gcc -Wall -Wextra random_number_generator.c -o random_number_generator
./random_number_generator

gcc -Wall -Wextra quick_sort.c -o quick_sort
./quick_sort
```