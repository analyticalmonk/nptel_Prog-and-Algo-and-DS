// !--- NPTEL Design and Analysis of Algorithms MOOC ---!
// --- Week-2 Assignment: SMS Dictionary (Sorting) ---
// Given the typical assignment from number keys to letters of the alphabet given above
// and given a dictionary of words, report the input sequence that matches the largest
// number of words in the dictionary. For example, if the dictionary consists of the words
// {at,on,good,no} then the answer is 66, because 66 matches both "on" and "no" while no
// other input matches more than one word in the dictionary. On the other hand, with the
// dictionary {at,on,good,no,home,gone}, the answer is 4663,
// because 4663 matches three words, "good", "home" and "gone" in the dictionary.

#include <stdio.h>
#include <stdlib.h>

// Compare function used in C standard library's qsort function
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

// Function prototype declarations
int dict_map (char*);
// void list_sort (int*);

int main() {
  int m, mapped_list[1000000], max = 1, count = 1, max_mapped;
  char* word_input;
  word_input = (char*)malloc(9 * sizeof(char));
  // input for the number of words in dictionary
  scanf ("%d", &m);
  // Code block for taking the input
  for (int i = 0; i < m; i++) {
    scanf ("%s", word_input);
    mapped_list[i] = dict_map(word_input);
  }
  free(word_input);

  // --- For debugging purpose ---
  // for (int i = 0; i < m; i++) {
  //   printf ("%d ", mapped_list[i]);
  // }

  // Sorted the list using C standard library's qsort() function
  qsort(&mapped_list[0], m, sizeof(int), cmpfunc);
  // list_sort(&mapped_list[0]);
  max_mapped = mapped_list[0];

  // --- Code block for finding out the most mapped sequence ---
  if (m > 1) {
    for (int i = 1; i < m; i++) {
      if (mapped_list[i] == mapped_list[i - 1]) {
        count++;
        if(count > max) {
          max = count;
          max_mapped = mapped_list[i];
        }
      }
      else if (mapped_list[i] != mapped_list[i - 1]) {
        count = 1;
      }
    }
  }
  printf ("%d", max_mapped);
  return 0;
}

// Function for mapping a word to its key input sequence
int dict_map(char* word) {
  int temp = 0, num = 1;
  for (int i = 0; *(word + i) != '\0'; i++) {
    if (i !=0) num *= 10;

    if (*(word + i) == 'a' | *(word + i) == 'b' | *(word + i) == 'c')
      temp  = 2;
    else if (*(word + i) == 'd' | *(word + i) == 'e' | *(word + i) == 'f')
      temp  = 3;
    else if (*(word + i) == 'g' | *(word + i) == 'h' | *(word + i) == 'i')
      temp  = 4;
    else if (*(word + i) == 'j' | *(word + i) == 'k' | *(word + i) == 'l')
      temp  = 5;
    else if (*(word + i) == 'm' | *(word + i) == 'n' | *(word + i) == 'o')
      temp  = 6;
    else if (*(word + i) == 'p' | *(word + i) == 'q' | *(word + i) == 'r' | *(word + i) == 's')
      temp  = 7;
    else if (*(word + i) == 't' | *(word + i) == 'u' | *(word + i) == 'v')
      temp  = 8;
    else if (*(word + i) == 'w' | *(word + i) == 'x' | *(word + i) == 'y' | *(word + i) == 'z')
      temp  = 9;

    if (i != 0) num += temp;
    else num = temp;
  }
  return num;
}

// void list_sort (int* first) {
//
// }
