#include <limits.h>
#include <stdlib.h>

// Does in-place merge within two subsections p..q and q+1..r of an array A.
// The subsections are each already sorted.
// See CLRS page 31
void merge(int* A, int p, int q, int r) {
  int l_length = q - p + 1;
  int r_length = r - q;
  // copy subsections to be merged into new arrays, with sentinel values at end
  // of each
  int* L = malloc((l_length + 1) * sizeof(int));
  int* R = malloc((r_length + 1) * sizeof(int));
  for (int i = p; i <= q; i++) {
    L[i - p] = A[i];
  }
  L[l_length] = INT_MAX;
  for (int i = q + 1; i <= r; i++) {
    R[i - (q + 1)] = A[i];
  }
  R[r_length] = INT_MAX;

  int l_front = 0;
  int r_front = 0;
  // iterate through combined length of two arrays, copying lowest of two fronts
  // into A
  for (int i = p; i <= r; i++) {
    int l_val = L[l_front];
    int r_val = R[r_front];
    if (l_val < r_val) {
      A[i] = l_val;
      l_front++;
    } else {
      A[i] = r_val;
      r_front++;
    }
  }
}
