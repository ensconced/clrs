#include "./length.h"

#include "../../test-utils.h"
#include "../123/123.h"
#include "../node.h"

int main() {
  struct node* list = buildOneTwoThree();
  int len = length(list);
  assertIntEqual(len, 3);
  return 0;
}
