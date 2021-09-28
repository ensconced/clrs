#include "./merge.h"

#include "../../test-utils.h"

int main() {
  int p = 4;
  int q = 8;
  int r = 12;
  int A[15] = {
      12, 3,  8,  2,       // 0..p-1     - this section is not sorted
      5,  12, 17, 18, 21,  // p..q       - this section is sorted
      10, 13, 17, 23,      // q+1..r     - this section is sorted
      14, 15               // r+1..n-1   - this section is not sorted
  };
  int expected[15] = {
      12, 3, 8, 2,  // 0..p-1 - this section is not sorted

      5, 10, 12, 13, 17, 17, 18, 21, 23,  // p..r - the two middle sections are
                                          // now merged into one sorted section

      14, 15  // r+1..n-1   - this section is not sorted
  };
  merge(A, p, q, r);
  assertArraysEqual(A, expected, 15);
  return 0;
}
