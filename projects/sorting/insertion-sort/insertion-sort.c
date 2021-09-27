#include <stdbool.h>

#include "../tests.h"

// sort an array, in place
void sort(int* arr, int length) {
  for (int j = 1; j < length; j++) {
    // for all numbers to the left...
    //   working from right to left...
    int rightVal = arr[j];
    int i;
    for (i = j - 1; i >= 0; i--) {
      int leftVal = arr[i];
      if (leftVal > rightVal) {
        // shift left val to the right by one position
        arr[i + 1] = leftVal;
      } else {
        break;
      }
    }
    arr[i + 1] = rightVal;
  }
}

int main() { testSortFn(&sort); }
