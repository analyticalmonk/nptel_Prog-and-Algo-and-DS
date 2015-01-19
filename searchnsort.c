// C program written by da-ta-vinci to show the use of binary search and
// selection sort.
// The program inputs an integer array and asks for the element to be searched.
// Internally, the program sorts the array using selection sort and proceeds to
// search the presence of required element through binary search.
// ~~~~~The program is compiled using the c99 standard~~~~~

#include <stdio.h>
#include <stdlib.h>

void swap (int*, int*);
void sel_sort (int*, int);
int bin_search (int[], int, int, int);

int main () {
  int a[100], length, target, status;
  // Input the length
  scanf ("%d", &length);
  // Array input
  for (int i = 0; i < length; i++) {
    scanf ("%d", &a[i]);
  }
  sel_sort (&a[0], length);
  // ___For debugging purpose___
  // for (int i = 0; i < length; i++) {
  //   printf ("%d ", a[i]);
  // }

  // Input element to be searched for
  scanf ("%d", &target);
  status = bin_search (a, 0, length, target);
  printf("\nStatus: %d\n", status);
  return 0;
}

void swap (int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

// Selection sort - iterative implementation
void sel_sort (int* first, int size) {
  int* small = first;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (*(first + j) < *small) {
        small = (first + j);
      }
    }
  swap (first + i, small);
  small = first + i + 1;
  }
}

// Selection sort - recursive implementation
// void sel_sort (int* first, int size) {
//
// }

// Binary search - Recursive implementation
int bin_search (int sequence[], int first, int last, int target) {
  if (first - last == 0) {
    return 0;
  }
  int mid = (first + last) / 2;
  if (sequence[mid] == target) {
    return 1;
  }
  else if (sequence[mid] < target) {
    return bin_search (sequence, mid + 1, last, target);
  }
  else if (sequence[mid] > target) {
    return bin_search (sequence, first, mid, target);
  }
}
