#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Forward declaration of both functions used
void add_grade(double **grades, int *size, int *count, int *allocs, double grade, int *totalAlloc);
double calculate_average(double *grades, int count);

// MAIN STARTS HERE!! The objective of this program is to take user input to create a list of grades using dynamic memory allocation
// For example, when started, the program will allocate 40 bytes to a double pointer list, which is enough for 5 numbers.
// Once 5 are supplied, the program will create a new double list with an increased amount of data allocated to account for 5 more double numbers.
// After the data is transferred, the old double list is freed to save memory
int main() {

    // Variable initialization for the grade list
    int size = 40;
    int count = 0;
    int allocs = 1;
    double grade;
    double *grades = malloc(size * sizeof(double));
    int totalSize = 40;

    if (grades == NULL) {
        fprintf(stderr, "Memory allocation failed for grades.\n");
        return EXIT_FAILURE;
    }

    printf("Enter a list of grades below where each grade is separated by a newline character.\n");
    printf("After the last grade is entered, enter a negative value to end the list.\n");

    // While loop to continually take input as long as the number is positive
    while (true) {
        if (scanf("%lf", &grade) != 1) {
            fprintf(stderr, "Invalid input. Please enter a valid number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        if (grade < 0) break; // End the loop on negative input
        add_grade(&grades, &size, &count, &allocs, grade, &totalSize);
    }

    // Finds the average of all the grades present
    if (count == 0) {
        fprintf(stderr, "No grades were entered.\n");
        free(grades);
        return EXIT_FAILURE;
    }

    double average = calculate_average(grades, count);
    printf("The average of %d grades is %.6f.\n", count, average);

    // Loops through every double in grades to print whether they are larger or smaller than the average
    for (int i = 0; i < count; i++) {
        if (*(grades + i) >= average) {
           printf("%d. The grade of %.6f is >= the average.\n", i + 1, *(grades + i));
        } else {
            printf("%d. The grade of %.6f is < the average.\n", i + 1, *(grades + i));
        }
    }

    // Ending print statements of the program that display the data freed and total heap usage statistics
    printf("Freed %d bytes from the heap at %p.\n", size, (void *)grades);
    free(grades);

    printf("Total heap usage: %d allocs, %d frees, %d bytes allocated\n", allocs, allocs, totalSize);

    return 0;
}

// Function to add grades into a list
void add_grade(double **grades, int *size, int *count, int *allocs, double grade, int *totalAlloc) {
    // Store the new grade into the address of the grade list by adjusting the pointer using count
    *(*grades + *count) = grade;
    printf("Stored %.6f in the heap at %p.\n", grade, (void *)(*grades + *count));
    // Increment the count by one each time
    (*count)++;

    // Check if the current count is more than the max size, which is 5, as the list accounts for 5 doubles or 40 bytes
    if (*count % 5 == 0) {
        printf("Stored %d grades to the heap at %p.\n", *count, (void *)*grades);
        printf("Heap at %p is full.\n", (void *)*grades);

        // Allocate new memory for 5 more doubles
        double *new_grades = malloc((*size + 40));

        if (new_grades == NULL) {
            fprintf(stderr, "Memory allocation failed for new grades.\n");
            free(*grades);
            exit(EXIT_FAILURE);
        }

        // Copy old grades to the new grades list
        for (int i = 0; i < *count; i++) {
            *(new_grades + i) = *(*grades + i);
        }

        printf("Allocated %d bytes to the heap at %p.\n", *size + 40, (void *)new_grades);
        printf("Copied %d grades from %p to %p.\n", *count, (void *)*grades, (void *)new_grades);
        printf("Freed %d bytes from the heap at %p.\n", *size, (void *)*grades);

        // Frees up the old grade data and replaces it with the new grade data, as well as adding 40 to the size to allocate, as well as the number of allocations (and respective frees)
        free(*grades);
        *grades = new_grades;
        *size += 40;
        *totalAlloc += *size;
        (*allocs)++;
    }
}

// Function that returns the average of all grades in a list, or all the grades up to a specified point in a list (usually to discount the use of the negative number to end the list)
double calculate_average(double *grades, int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += *(grades + i);
    }
    return sum / count;
}
