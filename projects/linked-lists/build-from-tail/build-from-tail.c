#include <stdlib.h>

#include "../node.h"

struct node* buildFromTail(int* array, int length) {
  struct node* listHead = NULL;
  struct node* listTail = NULL;
  for (int i = 0; i < length; i++) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = array[i];
    newNode->next = NULL;
    if (i == 0) {
      listHead = newNode;
    } else {
      listTail->next = newNode;
    }
    listTail = newNode;
  }
  return listHead;
}
