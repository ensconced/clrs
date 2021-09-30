#include <stdlib.h>

#include "../node.h"
#include "../push/push.h"

struct node* listFromArray(int* array, int length) {
  struct node* listHead = NULL;
  struct node** headRef = &listHead;
  for (int i = length - 1; i >= 0; i--) {
    push(headRef, array[i]);
  }
  return listHead;
}
