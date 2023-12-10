
# Shell Sort Project

## Overview
This project focuses on implementing Shell Sort in C for both arrays and linked lists. The goal is to apply understanding of basic data structures and sorting algorithms, particularly Shell Sort, using a specific sequence for sorting.

## Features
- Implementation of Shell Sort for arrays and linked lists.
- Dynamic sequence generation for Shell Sort without pre-computation or storage in the program.
- Functions to load and save data from and to files in binary format.
- Calculation and output of the number of comparisons performed during sorting.

## Files
- `shell_array.c` and `shell_list.c`: Core implementation files for sorting arrays and linked lists respectively.
- `pa1.c`: Main function file to invoke functions in `shell_array.c` and `shell_list.c`.
- `.h` files (`shell_array.h`, `shell_list.h`, `list_of_list.h`): Header files provided for the project.

## How to Run
1. Compile the program using GCC with the following command:
   ```
   gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic shell_array.c shell_list.c pa1.c -o pa1
   ```
2. To sort an array, use:
   ```
   ./pa1 -a input.b output.b
   ```
   This command loads long integers from `input.b`, sorts them using Shell Sort, and saves the sorted integers in `output.b`.

3. To sort a linked list, use:
   ```
   ./pa1 -l input.b output.b
   ```
   Similar to the array, this command loads, sorts, and saves long integers using a linked list.

