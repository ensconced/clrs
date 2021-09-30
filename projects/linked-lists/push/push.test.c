#include "./push.h"

#include "../../test-utils.h"
#include "../123/123.h"
#include "../node.h"

int main() {
  struct node* list = buildOneTwoThree();
  push(&list, 4);
  int expected[4] = {4, 1, 2, 3};
  assertListEqualToArray(list, expected, 4);
  return 0;
}
