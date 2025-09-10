#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];   // choose first element as pivot
    int i = low - 1;
    int j = high + 1;

    while (1) {
        // find leftmost element >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // find rightmost element <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // if two pointers meet or cross
        if (i >= j)
            return j;

        // swap elements at i and j
        swap(&arr[i], &arr[j]);
    }
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = hoarePartition(arr, low, high);

        quickSort(arr, low, p);      // sort left side
        quickSort(arr, p + 1, high); // sort right side
    }
}

// Driver code
int main() {
    int arr[] = {42, 7, 19, 73, 3, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

