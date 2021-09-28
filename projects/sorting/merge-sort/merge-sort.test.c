#include "./merge-sort.h"

#include "../../test-utils.h"

int main() {
  int A[15] = {12, 3, 8, 2, 5, 12, 17, 18, 21, 10, 13, 17, 23, 14, 15};
  int expected[15] = {2, 3, 5, 8, 10, 12, 12, 13, 14, 15, 17, 17, 18, 21, 23};
  sort(A, 15);
  assertArraysEqual(A, expected, 15);
  return 0;
}
