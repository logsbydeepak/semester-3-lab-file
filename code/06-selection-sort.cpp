#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    int index = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[index] > arr[j]) {
        index = j;
      }
    }
    swap(arr[i], arr[index]);
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
  selectionSort(arr);
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
