#include <stdlib.h>

#include "../node.h"
/*
  Generally, using push would add a node to the head of a list.
  But here we use it to actually add to the tail. The trick is
  to keep a reference to the last (tail-end) pointer of the list,
  and to pass that to push (instead of the head pointer which is
  what you would normally pass to push).
*/
struct node* buildFromTailUsingPush(int* arr, int length) {
  struct node* head = NULL;
  struct node** lastPtrRef = &head;
  for (int i = 0; i < length; i++) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = arr[i];
    newNode->next = NULL;
    *lastPtrRef = newNode;
    lastPtrRef = &(newNode->next);
  }
  return head;
}
