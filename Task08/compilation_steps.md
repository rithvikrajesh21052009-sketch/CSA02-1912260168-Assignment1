# Task 8 — GCC compilation stages

Run these commands inside the task folder (replace `task04.c` with a source file in your repository):

```sh
gcc -E task04.c -o task04.i
gcc -S task04.c -o task04.s
gcc -c task04.c -o task04.o
gcc task04.o -o task04
gcc -std=c11 -Wall -Wextra -Wpedantic task04.c -o task04
```

- `-E`: preprocessor output (`.i`); macros are expanded and included headers are inserted.
- `-S`: assembly output (`.s`).
- `-c`: object file (`.o`), without linking.
- Link: combines object code and libraries into an executable.

Example error categories:
- Compile-time: misspelling `pritnf` in code with an incompatible declaration or syntax error.
- Link-time: calling a function declared but never defined.
- Run-time: processing invalid user input or a divide-by-zero operation.
- Warnings: enable `-Wall -Wextra -Wpedantic`, then record and fix warnings actually produced on your compiler.

Multi-file example:
```sh
gcc -std=c11 -Wall -Wextra -c input.c -o input.o
gcc -std=c11 -Wall -Wextra -c tariff.c -o tariff.o
gcc -std=c11 -Wall -Wextra -c report.c -o report.o
gcc input.o tariff.o report.o -o billing
```
