#include <stdio.h>

void comb_sort(int *array, int size) {
    int gap = size;
    int swaps = 1;
    int i, j;

    while (gap > 1 || swaps) {
        gap = (int) (gap / 1.24733);
        if (gap < 1)
            gap = 1;
        swaps = 0;
        for (i = 0; i < size - gap; ++i) {
            j = i + gap;
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                swaps = 1;
            }
        }
    }
}


void countingSort(int *array, int size, int place) {
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++) {
        if (((array[i] / place) % 10) > max)
            max = (array[i] / place) % 10;
    }
    int count[max + 1];

    for (int i = 0; i <= max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radix_sort(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

int main() {
    FILE *myFile;
    myFile = fopen("../input.txt", "r");

    int n = 0;
    fscanf(myFile, "%d", &n);
    int comb_array[n];
    int radix_array[n];

    for (int i = 0; i < n; i++) {
        int element;
        fscanf(myFile, "%d", &element);
        comb_array[i] = element;
        radix_array[i] = element;
    }

    FILE *outputFile = fopen("../output.txt", "w");
    comb_sort(comb_array, n);
    fprintf(outputFile, "Comb sort result: ");
    for (int i = 0; i < n; ++i) {
        fprintf(outputFile, "%d ", comb_array[i]);
    }
    radix_sort(radix_array, n);
    fprintf(outputFile, "\nRadix sort result: ");
    for (int i = 0; i < n; ++i) {
        fprintf(outputFile, "%d ", radix_array[i]);
    }
}