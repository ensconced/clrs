#include "./sort.test.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../test-utils.h"

void test(sortFn sort, int* arr, int* expected, int length) {
  sort(arr, length);
  assertArraysEqual(arr, expected, length);
}

void testSortFn(sortFn sort) {
  int test1[] = {3, 2, 1};
  int expected1[] = {1, 2, 3};
  test(sort, test1, expected1, 3);

  int test2[] = {1, 2, 3};
  int expected2[] = {1, 2, 3};
  test(sort, test2, expected2, 3);

  int test3[] = {6, 6, 1, 5};
  int expected3[] = {1, 5, 6, 6};
  test(sort, test3, expected3, 4);
}
