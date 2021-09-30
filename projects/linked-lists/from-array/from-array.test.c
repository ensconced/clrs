#include "./from-array.h"

#include "../../test-utils.h"

int main() {
  int arr[4] = {1, 2, 3, 4};
  struct node* list = listFromArray(arr, 4);
  assertListEqualToArray(list, arr, 4);
}
