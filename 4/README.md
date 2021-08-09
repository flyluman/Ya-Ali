## INFO

#### input.txt:

contains the value of n followed by n integers.

#### random_number_generator.c:

will create the file input.txt

#### bubble+count_sort.c:

will input generated file, sort using bubble + counting sort & output required time in ms.

#### Compile & Run:

Use [GCC](https://gcc.gnu.org/) to compile random_number_generator.c & bubble+count_sort.c

```bash
gcc -Wall -Wextra random_number_generator.c -o random_number_generator
./random_number_generator 10000

gcc -Wall -Wextra bubble+count_sort.c -o bubble+count_sort
./bubble+count_sort
```