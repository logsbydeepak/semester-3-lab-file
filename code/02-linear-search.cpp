#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int> &arr, int key) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int main() {
  vector<int> arr = {10, 5, 30, 20, 25, 15};
  int key = 20;

  for (int el : arr) {
    cout << el << " ";
  }
  cout << endl;
  cout << "Key: " << key << endl;

  int pos = linearSearch(arr, key);
  if (pos != -1) {
    cout << "Element found at index " << pos << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}

/*
10 5 30 20 25 15
Key: 20
Element found at index 3
*/
