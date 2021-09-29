#include "./123.h"

#include "../../test-utils.h"

int main() {
  int arr[] = {1, 2, 3};

  struct node* listHead1 = buildOneTwoThree();
  assertListEqualToArray(listHead1, arr, 3);

  struct node* listHead2 = terseOneTwoThree();
  assertListEqualToArray(listHead2, arr, 3);

  return 0;
}
