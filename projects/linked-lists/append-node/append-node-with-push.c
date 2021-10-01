#include "../node.h"
#include "../push/push.h"
/*
  Here we're sort of abusing the push function to
  append to the tail of a list.
*/
void appendNodeWithPush(struct node** listHeadRef, int val) {
  struct node** tailRef = listHeadRef;
  // Iterate down the list until tailRef is pointing to the NULL at the end -
  // then pass that to push as if it's a headRef. This lets us use push
  // to actually append at the tail end of the list.
  while (*tailRef) {
    tailRef = &((*tailRef)->next);
  }
  push(tailRef, val);
}
