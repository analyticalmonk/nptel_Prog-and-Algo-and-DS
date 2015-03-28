// listInterface.h created with all the function prototypes

include "list.h"

// Returns the number of elements in the list
int size(node*);
int isEmpty(node*);

// Decision questions given a pointer
int isFirst(node*, node*);
int isLast(node*, node*);

// functions to return pointers to specific queries
node* first(node*);
node* last(node*);
node* before(node*, node*, int);
node* after(node*, node*);

// Update methods
void replaceElement(node*, int);
void swapElement(node*, node*);
node* insertBefore(node*, node* int);
void insertAfter(node*, node* int);
node* insertFirst(node*, int);
void insertLast(node*, int);
node* eliminate(node*, node*);
