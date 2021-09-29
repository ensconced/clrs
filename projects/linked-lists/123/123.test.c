#include "./123.h"

#include "../../test-utils.h"

int main() {
  struct node* listHead = BuildOneTwoThree();
  int arr[] = {1, 2, 3};
  assertListEqualToArray(listHead, arr, 3);
  return 0;
}
