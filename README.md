# GradeCalculator

## Overview

`GradeCalculator.c` is a C program that dynamically manages a list of grades inputted by the user, calculates the average, and displays whether each grade is above or below the average. The program employs dynamic memory allocation to handle an expanding list of grades efficiently.

## Features

- Dynamically allocates memory for grades, starting with an initial size sufficient for five grades.
- Automatically increases the allocated memory by 40 bytes (for five additional grades) when the current capacity is reached.
- Calculates the average of the entered grades.
- Provides feedback on whether each grade is above or below the average.
- Tracks and displays memory usage statistics, including total allocations and bytes freed.
- A COMPLETE lack of arrays or array syntax, relying entirely on pointer arithmetic.

## Usage

1. Compile the program using a C compiler (e.g., `gcc`):
   ```bash
   gcc GradeCalculator.c -o GradeCalculator
2. Run the program:
   ```bash
   ./GradeCalculator
3. Enter a list of grades, each separated by a newline. After entering the last grade, input a negative value to finish the list.

## Examples
  Enter a list of grades below where each grade is separated by a newline character. After the last grade is entered, enter a negative value to end the list. 90 85 78 92 88 -1 The average of 5 grades is 86.600000.

  1. The grade of 90.000000 is >= the average.
  2. The grade of 85.000000 is < the average.
  3. The grade of 78.000000 is < the average.
  4. The grade of 92.000000 is >= the average.
  5. The grade of 88.000000 is >= the average. Freed 40 bytes from the heap at 0x7ffde4c02230. Total heap usage: 1 allocs, 1 frees, 40 bytes allocated.

## License

This project is licensed under the MIT License.
