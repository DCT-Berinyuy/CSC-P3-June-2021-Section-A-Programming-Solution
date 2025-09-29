/*
Program: Section A (Programming) – June 2021
Author: Mr.DCT
Date: 9/22/2025

Task 1 — Algorithms & Explanations (11 marks):
(a) Copy Pascal triangle and attach next two lines (2 marks)
    1
    1   1
    1   2   1
    1   3   3   1
    1   4   6   4   1
    1   5   10  10  5   1
    1   6   15  20  15  6   1

(b) Algorithm: Fill the leading diagonal of Pascal triangular matrix A (n rows) (2 marks)
Algorithm FillLeadingDiagonal(A, n)
    For i from 0 to n-1 Do
        A[i][i] <- 1
    EndFor
EndAlgorithm

(c) Algorithm: Fill the first column with 1s and the remaining columns with 0s (3 marks)

Algorithm FillFirstColumnAndClear(A, n)
    For i from 0 to n-1 Do
        A[i][0] <- 1
        For j from 1 to n-1 Do
            A[i][j] <- 0
        EndFor
    EndFor
EndAlgorithm

(d) Algorithm: Fill internal Pascal entries (exclude first and last elements) (4 marks)
Algorithm FillInteriorEntries(A, n)
    For i from 2 to n-1 Do
        For j from 1 to n-1 Do
            A[i][j] <- A[i-1][j] + A[i-1][j-1]
        EndFor
        For j from i+1 to n-1 Do
            A[i][j] <- 0 // Entries beyond Diagonal = 0
        EndFor
    EndFor
EndAlgorithm
    

    
*/

// Task 2 — Implementation in C (17 marks total):

#include <stdio.h>

#define MAX 50   /* maximum supported N, change if needed */

/* Function prototypes */
void fill_leading_diagonal(int A[][MAX], int n);
void fill_first_column_and_clear(int A[][MAX], int n);
void fill_interior_entries(int A[][MAX], int n);
void print_matrix(int A[][MAX], int n);

int main(void) {
    int A[MAX][MAX];
    int n;
    
    /* Input N */
    printf("Enter N (size of Pascal triangle, N <= %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid N.\n");
        return 1;
    }

    /* Step 1: Set leading diagonal A[i][i] = 1 */
    fill_leading_diagonal(A, n);
    
    /* Step 2: Initialize and set first column (A[i][0]=1) and clear others */
    fill_first_column_and_clear(A, n);


    /* Step 3: Fill interior entries using Pascal rule */
    fill_interior_entries(A, n);

    /* Step 4: Print matrix to screen (this is the program output) */
    printf("\nPascal triangle stored in an %dx%d matrix:\n\n", n, n);
    print_matrix(A, n);

    return 0;
}

/* Function definitions */

/* Step 1: Set leading diagonal A[i][i] = 1 */
void fill_leading_diagonal(int A[][MAX], int n) {
    int i;
    for (i = 0; i < n; i++) {
        A[i][i] = 1;
    }
}

/* Step 2: Initialize and set first column (A[i][0]=1) and clear others */
void fill_first_column_and_clear(int A[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        A[i][0] = 1;
        for (j = 1; j < n; j++) {
            A[i][j] = 0;
        }
    }
}

/* Step 3: Fill interior entries using Pascal rule & Ensure entries beyond diagonal are 0 */
void fill_interior_entries(int A[][MAX], int n) {
    int i, j;
    for (i = 2; i < n; i++) {
        for (j = 1; j <= i - 1; j++) {
            /* Pascal recurrence */
            A[i][j] = A[i-1][j-1] + A[i-1][j];
        }
        /* Ensure entries beyond diagonal are 0 (optional here) */
        for (j = i+1; j < n; j++) {
            A[i][j] = 0;
        }
    }
}

/* Step 4: Print matrix to screen (this is the program output) */
void print_matrix(int A[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}













