
#include "./tests.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void logArray(int* arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", arr[i]);
    if (i < length - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

void logTestFailure(int* received, int* expected, int length) {
  printf("Expected: ");
  logArray(expected, length);
  printf("Received: ");
  logArray(received, length);
}

void assertArraysEqual(int* received, int* expected, int length) {
  for (int i = 0; i < length; i++) {
    if (received[i] != expected[i]) {
      logTestFailure(received, expected, length);
      exit(1);
    }
  }
}

void testSortFn(sortFn sort) {
  int test_cases[][2][3] = {{{1, 2, 3}, {1, 2, 3}}};
  int(*test_case)[3] = test_cases[0];
  printf("%d", (*test_case)[0]);
}
