#include "./push.h"

#include "../../test-utils.h"
#include "../123/123.h"
#include "../node.h"

void pushToExistingList() {
  struct node* list = buildOneTwoThree();
  push(&list, 4);
  int expected[4] = {4, 1, 2, 3};
  assertListEqualToArray(list, expected, 4);
}

void buildListByPushing() {
  struct node* listHead = NULL;
  struct node** headRef = &listHead;
  push(headRef, 1);
  push(headRef, 2);
  push(headRef, 3);
  int expected[3] = {3, 2, 1};
  assertListEqualToArray(*headRef, expected, 3);
}

int main() {
  pushToExistingList();
  buildListByPushing();
  return 0;
}
