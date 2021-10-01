#include "./append-node-with-push.h"

#include "../../test-utils.h"
#include "../node.h"

int main() {
  struct node* list = NULL;
  appendNodeWithPush(&list, 1);
  appendNodeWithPush(&list, 2);
  appendNodeWithPush(&list, 3);
  int arr[3] = {1, 2, 3};
  assertListEqualToArray(list, arr, 3);
}
