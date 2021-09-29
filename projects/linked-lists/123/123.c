#include <stddef.h>
#include <stdlib.h>

#include "../node.h"

/*
  Build the list {1, 2, 3} in the heap and store its head pointer
  in a local stack variable. Returns the head pointer to the caller.
*/
struct node* buildOneTwoThree() {
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;

  head = malloc(sizeof(struct node));
  second = malloc(sizeof(struct node));
  third = malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;
  return head;
}

// A more terse version of the same...
struct node* terseOneTwoThree() {
  struct node* head = malloc(sizeof(struct node));
  head->data = 1;
  head->next = malloc(sizeof(struct node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->data = 3;
  head->next->next->next = NULL;
  return head;
}
