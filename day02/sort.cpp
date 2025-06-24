#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> arr = {4, 2, 1, 6, 8};

  // bubble sort
  for (int i = 0; i < arr.size(); i++) {
    for (int x = 0; x < arr.size() - i - 1; x++) {
      if (arr[x] > arr[x + 1]) {
        std::swap(arr[x], arr[x + 1]);
      }
    }
  }

  // test
  for (int num : arr) {
    std::cout << num;
  }
  std::cout << '\n';

  // selection sort
  for (int i = 0; i < arr.size(); i++) {
    for (int x = i + 1; x < arr.size(); x++) {
      if (arr[i] > arr[x]) {
        std::swap(arr[i], arr[x]);
      }
    }
  }

  // test
  for (int num : arr) {
    std::cout << num;
  }
  std::cout << '\n';

  return 0;
}