#include <stdlib.h>

#include "../node.h"

/*
  Takes a list and a data value.
  Creates a new link with the given data and pushes
  it onto the front of the list.
  The list is not passed in by its head pointer.
  Instead the list is passed in as a "reference" pointer
  to the head pointer -- this allows us to modify the caller's
  memory.
*/

void push(struct node** headRef, int data) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = *headRef;
  *headRef = newNode;
}
