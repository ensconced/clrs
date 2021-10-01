#include "./append-node.h"

#include "../../test-utils.h"
#include "../node.h"

int main() {
  struct node* list = NULL;
  appendNode(&list, 1);
  appendNode(&list, 2);
  appendNode(&list, 3);
  int arr[3] = {1, 2, 3};
  assertListEqualToArray(list, arr, 3);
  return 0;
}
