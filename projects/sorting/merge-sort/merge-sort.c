#include "./merge.h"

void sort_subsection(int* A, int p, int r) {
  // If the subsection only has a length of 1, then it's trivially sorted
  // already.
  if (p == r) return;

  // Otherwise, split the subsection in two.
  int q = (p + r) / 2;

  // sort left hand part
  sort_subsection(A, p, q);

  // sort right hand part
  sort_subsection(A, q + 1, r);

  // merge the two parts
  merge(A, p, q, r);
}

void sort(int* A, int length) { sort_subsection(A, 0, length - 1); }
