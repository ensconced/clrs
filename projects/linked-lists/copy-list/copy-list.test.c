#include "./copy-list.h"

#include "../../test-utils.h"
#include "../from-array/from-array.h"

int main() {
  int arr[3] = {1, 2, 3};
  struct node* list = listFromArray(arr, 3);
  struct node* copy = copyList(list);
  assertListEqualToArray(copy, arr, 3);
  return 0;
}
