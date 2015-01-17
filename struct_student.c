#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_record{
  char name[20];
  int year_of_joining;
} student_list;

student_list* search_for(student_list*, int, int);

int main() {
  int i, number_of_records, operation_code;
  scanf("%d", &number_of_records);
  student_list* students;
  student_list* target_record;
  students = (student_list*)malloc(number_of_records*sizeof(student_list));
  for (i = 0; i < number_of_records; i++){
    // Different methods to access the struct fields
    scanf("%s %d", (students + i)->name, &((students+i)->year_of_joining));
    // scanf("%s %d", (*(students + i)).name, &(*(students+i)).year_of_joining);
  }

  scanf("%d", &operation_code);
  if (!(operation_code == 1 | operation_code == 2)){
    printf("Wrong choice. Terminating biatchh!");
    return -1;
  }
  target_record = search_for(students, operation_code, number_of_records);
  // For debugging purpose
  // for (i = 0; i < number_of_records; i++){
  //   // printf("%s %d\n", (*(students+i)).name, (*(students+i)).year_of_joining);
  //   printf("%s %d\n", (students + i)->name, (students + i)->year_of_joining);
  // }
  free(students);
  printf("\n");
  printf("%s %d\n", (*(target_record)).name, (*(target_record)).year_of_joining);
  printf("\n");
  return 0;
}

student_list* search_for(student_list* list, int operation, int size){
  student_list* target = list;
  for (int i = 0; i < size; i++){
    if(operation == 1){
      if(strcmp(target->name, (list+i)->name) > 0){
        target = list + i;
      }
    }
    else if(operation == 2){
      if(target->year_of_joining > (list + i)->year_of_joining){
        target = list + i;
      }
    }
  }
  return target;
}
