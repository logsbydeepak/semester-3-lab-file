#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
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
  bubbleSort(arr);
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
