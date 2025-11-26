#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;

  int left = low;
  int right = mid + 1;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low == high) {
    return;
  }

  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
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
  mergeSort(arr, 0, arr.size() - 1);
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
