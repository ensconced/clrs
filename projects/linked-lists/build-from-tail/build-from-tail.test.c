#include "./build-from-tail.h"

#include "../../test-utils.h"
#include "../node.h"

int main() {
  int arr[3] = {1, 2, 3};
  struct node* list = buildFromTail(arr, 3);
  assertListEqualToArray(list, arr, 3);
  return 0;
}
