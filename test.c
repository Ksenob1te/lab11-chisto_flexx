#include <stdio.h>
#include <stdlib.h>

int main() {
    int ** matrix;
    int * sums;
    int n = 0, m = 0;
    printf("Type in n and m, where m - number of columns, n - number of rows:\n");
    scanf("%d%d", &m, &n);
    printf("Type in matrix with %dx%d size:\n", n, m);
    matrix = malloc(n * sizeof(int*));
    sums = calloc(m, sizeof(int));
    for (int i = 0; i < n; ++i) {
        matrix[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j) {
            scanf("%d", matrix[i] + j);
            sums[j] += matrix[i][j];
        }
    }
    int max_value = -INT_MAX, max_column = -INT_MAX;
    for (int i = 0; i < m; ++i) {
        if (sums[i] > max_value) {
            max_value = sums[i];
            max_column = i;
        }
    }
    printf("Max sum of the column is: %d in column: %d\n", max_value, max_column + 1);
    return 0;
} 