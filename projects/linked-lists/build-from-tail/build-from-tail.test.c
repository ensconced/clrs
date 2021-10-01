#include "./build-from-tail.h"

#include "../../test-utils.h"
#include "../node.h"
#include "./build-from-tail-using-push.h"
#include "./build-from-tail-with-dummy.h"

int main() {
  int arr[3] = {1, 2, 3};
  struct node* l1st1 = buildFromTail(arr, 3);
  assertListEqualToArray(l1st1, arr, 3);

  struct node* list2 = buildFromTailWithDummy(arr, 3);
  assertListEqualToArray(list2, arr, 3);

  struct node* list3 = buildFromTailUsingPush(arr, 3);
  assertListEqualToArray(list3, arr, 3);

  return 0;
}
