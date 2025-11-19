#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> readMatrix(int r, int c) {
  vector<vector<int>> m(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }
  return m;
}

void printMatrix(const vector<vector<int>> &m) {
  for (auto &row : m) {
    for (auto &val : row) {
      cout << val << "\t";
    }
    cout << endl;
  }
}

vector<vector<int>> addMatrix(const vector<vector<int>> &A,
                              const vector<vector<int>> &B) {
  int r = A.size(), c = A[0].size();
  vector<vector<int>> res(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      res[i][j] = A[i][j] + B[i][j];
    }
  }
  return res;
}

vector<vector<int>> subMatrix(const vector<vector<int>> &A,
                              const vector<vector<int>> &B) {
  int r = A.size(), c = A[0].size();
  vector<vector<int>> res(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      res[i][j] = A[i][j] - B[i][j];
    }
  }
  return res;
}

vector<vector<int>> multiplyMatrix(const vector<vector<int>> &A,
                                   const vector<vector<int>> &B) {
  int r1 = A.size(), c1 = A[0].size();
  int r2 = B.size(), c2 = B[0].size();

  vector<vector<int>> res(r1, vector<int>(c2, 0));

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      for (int k = 0; k < c1; k++) {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return res;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>> &A) {
  int r = A.size(), c = A[0].size();
  vector<vector<int>> t(c, vector<int>(r));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      t[j][i] = A[i][j];
    }
  }

  return t;
}

int main() {
  int r1, c1, r2, c2;

  cout << "Enter rows & cols of Matrix A: ";
  cin >> r1 >> c1;

  cout << "Enter rows & cols of Matrix B: ";
  cin >> r2 >> c2;

  cout << "Enter " << r1 << "x" << c1 << " Matrix A:" << endl;
  vector<vector<int>> A = readMatrix(r1, c1);
  cout << "Enter " << r2 << "x" << c2 << " Matrix B:" << endl;
  vector<vector<int>> B = readMatrix(r2, c2);
  cout << endl;

  if (r1 == r2 && c1 == c2) {
    cout << "A + B =" << endl;
    printMatrix(addMatrix(A, B));

    cout << "A - B =" << endl;
    printMatrix(subMatrix(A, B));
  } else {
    cout << "Addition & subtraction not possible (dimension mismatch)" << endl;
  }

  if (c1 == r2) {
    cout << "A × B =" << endl;
    printMatrix(multiplyMatrix(A, B));
  } else {
    cout << "Multiplication not possible (A columns != B rows)" << endl;
  }

  cout << "Transpose of A:" << endl;
  printMatrix(transposeMatrix(A));

  cout << "Transpose of B:" << endl;
  printMatrix(transposeMatrix(B));

  return 0;
}

/*
Enter rows & cols of Matrix A: 3 3
Enter rows & cols of Matrix B: 3 3
Enter 3x3 Matrix A:
1 2 3
4 5 6
7 8 9
Enter 3x3 Matrix B:
10 11 12
13 14 15
16 17 18

A + B =
11      13      15
17      19      21
23      25      27
A - B =
-9      -9      -9
-9      -9      -9
-9      -9      -9
A × B =
84      90      96
201     216     231
318     342     366
Transpose of A:
1       4       7
2       5       8
3       6       9
Transpose of B:
10      13      16
11      14      17
12      15      18
*/
