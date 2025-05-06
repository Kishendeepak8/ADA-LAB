#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n-1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int n, i, *a;
    char choice = 'y';
    clock_t start, end;

    while (choice == 'y' || choice == 'Y') {
        printf("Enter number of elements to sort: ");
        scanf("%d", &n);

        a = (int*)malloc(n * sizeof(int));
        if (!a) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the elements:\n");
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        start = clock();
        heapSort(a, n);
        end = clock();

        printf("Sorted elements:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements = %f seconds\n", n, time_taken);

        FILE *fp = fopen("heapsort_times.csv", "a");
        if (fp) {
            fprintf(fp, "%d,%f\n", n, time_taken);
            fclose(fp);
        } else {
            printf("Unable to write to file!\n");
        }

        printf("Do you want to run again? (y/n): ");
        scanf(" %c", &choice);
        free(a);
    }

    return 0;
}
