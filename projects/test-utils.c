#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./linked-lists/node.h"

void logArray(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", arr[i]);
    if (i < length - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

void logArrayMismatch(int *received, int *expected, int length) {
  puts("Expected: ");
  logArray(expected, length);
  puts("Received: ");
  logArray(received, length);
}

void logList(struct node *listHead) {
  struct node *currentNode = listHead;
  if (currentNode == NULL) return;
  bool first = true;
  do {
    int val = currentNode->data;
    if (first) {
      printf("%d", val);
      first = false;
    } else {
      printf(", %d", val);
    }
  } while ((currentNode = currentNode->next));
  printf("\n");
}

void logListMismatchAgainstArray(struct node *listHead,
                                 int *array,
                                 int length) {
  puts("Received list:");
  logList(listHead);
  puts("Expected (reference array):");
  logArray(array, length);
}

void assertArraysEqual(int *received, int *expected, int length) {
  for (int i = 0; i < length; i++) {
    if (received[i] != expected[i]) {
      logArrayMismatch(received, expected, length);
      exit(1);
    }
  }
}

void assertListEqualToArray(struct node *listHead, int *array, int length) {
  if (listHead == NULL) {
    if (length == 0) {
      return;
    } else {
      logListMismatchAgainstArray(listHead, array, length);
      exit(1);
    }
  }
  struct node *currentNode = listHead;
  int i = 0;
  do {
    int val = currentNode->data;
    if (i > length) {
      logListMismatchAgainstArray(listHead, array, length);
      exit(1);
    }
    if (val != array[i]) {
      logListMismatchAgainstArray(listHead, array, length);
      exit(1);
    }
    i++;
  } while ((currentNode = currentNode->next));
}
