#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &arr, int key) {
  int low = 0, high = arr.size() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (key < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {5, 10, 15, 20, 25, 30};
  int key = 25;

  for (int el : arr) {
    cout << el << " ";
  }
  cout << endl;
  cout << "Key: " << key << endl;

  int pos = binarySearch(arr, key);
  if (pos != -1) {
    cout << "Element found at index " << pos << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}

/*
5 10 15 20 25 30
Key: 25
Element found at index 4
*/
