// list.h created to define node data type and will be used in listmethods.c

typedef struct container {
  int value;
  struct container* next;
} node;
