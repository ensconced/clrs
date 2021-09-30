#include <stdlib.h>

#include "../node.h"

/*
  Given a linked list head pointer, compute
  and return the number of nodes in the list.
*/

int length(struct node* head) {
  struct node* current = head;
  int count = 0;

  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}
