#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

void print(const vector<int> &arr) {
  for (int el : arr) {
    cout << el << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {13, 46, 24, 13, 52, 20, 9};

  cout << "Before: " << endl;
  print(arr);
  insertionSort(arr);
  cout << "After: " << endl;
  print(arr);

  return 0;
}

/*
Before:
13 46 24 13 52 20 9
After:
9 13 13 20 24 46 52
*/
