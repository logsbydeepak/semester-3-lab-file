#include <iostream>
#include <vector>
using namespace std;

int fPivot(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j) {
    while (i <= high && arr[i] <= pivot) {
      i++;
    }

    while (j >= low && arr[j] > pivot) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[low], arr[j]);

  return j;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pIndex = fPivot(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
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
  quickSort(arr, 0, arr.size() - 1);
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
