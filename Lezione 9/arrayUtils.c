#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(int* array, int size) {
  for (int i = 0; i < size / 2; i++) {
    swap(&array[i], &array[size - i - 1]);
  }
}

int partition(int array[], int p, int q) {
  int pivot = array[q];
  int i = p - 1;

  for (int j = p; j < q; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[q]);
  return i + 1;
}

void quickSort(int array[], int p, int q) {
  if (p < q) {
    int p = partition(array, p, q);
    quickSort(array, p, q - 1);
    quickSort(array, p + 1, q);
  }
}

int main() {
  int size;
  printf("%s", "Insert the size of the array: ");
  scanf("%d", &size);

  int array[size];

  printf("%s", "Insert the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  // printf("%s", "The array reversed is: ");
  // reverse(array, size);

  quickSort(array, 0, size - 1);
  printf("%s", "The sorted array is: ");

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}