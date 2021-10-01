#include <stdlib.h>

#include "../node.h"

struct node* buildFromTailWithDummy(int* arr, int length) {
  // NB this isn't a pointer - we're just declaring the struct - so the memory
  // for the struct is allocated automatically, directly on the stack.
  struct node dummy;
  // dummy is not a pointer, so we use the dot operator instead of -> here.
  dummy.next = NULL;

  struct node* tail = &dummy;

  for (int i = 0; i < length; i++) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = arr[i];
    tail->next = newNode;
    tail = newNode;
  }

  return dummy.next;
}
