// C program written by da-ta-vinci to show the use of merge sort.
// The program inputs an integer array and internally, the program
// sorts the array using merge sort (recursive) and proceeds to
// print the sorted array.
// ~~~~~The program is compiled using the c99 standard~~~~~

#include <stdio.h>

void merge_sort(int*, int, int, int*);
void merge(int*, int, int*, int, int*);

int main () {
  int a[100], b[100], length;
  // Length of input array
  scanf ("%d", &length);
  // Obtain input array
  for (int i = 0; i < length; i++) {
    scanf ("%d", &a[i]);
  }
  // Call to merge_sort
  merge_sort(&a[0], 0, length, &b[0]);
  for (int i = 0; i < length; i++) {
    printf ("%d ", b[i]);
  }
  printf ("\n");
  return 0;
}

void merge_sort(int* original, int start, int end, int* result) {
  if (end - start == 1) {
    *(result) = *(original + start);
  }
  int mid, l[100], r[100];
  if (end - start > 1) {
    mid = (end + start) / 2;
    merge_sort (original, start, mid, &l[0]);
    merge_sort (original, mid, end, &r[0]);
    merge(&l[0], mid - start, &r[0], end - mid, result);
  }
}

void merge(int* a, int m, int* b, int n, int* c) {
  int i =0, j = 0, k = 0;
  while (k < m + n) {
    if (*(a + i) <= *(b + j)) {
      *(c + k) = *(a + i);
      i++; k++;
    }
    else if (*(a + i) > *(b + j)) {
      *(c + k) = *(b + j);
      j++; k++;
    }
  }
}
