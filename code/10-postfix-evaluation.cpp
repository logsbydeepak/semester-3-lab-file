#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int floorDiv(int a, int b) {
  if (a * b < 0 && a % b != 0) {
    return (a / b) - 1;
  }
  return a / b;
}

int evaluatePostfix(vector<string> &arr) {
  stack<int> st;

  for (string token : arr) {
    if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
      st.push(stoi(token));
    } else {
      int val1 = st.top();
      st.pop();
      int val2 = st.top();
      st.pop();

      if (token == "+")
        st.push(val2 + val1);
      else if (token == "-")
        st.push(val2 - val1);
      else if (token == "*")
        st.push(val2 * val1);
      else if (token == "/")
        st.push(floorDiv(val2, val1));
      else if (token == "^")
        st.push((int)pow(val2, val1));
    }
  }
  return st.top();
}

int main() {
  vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
  cout << "Expression: ";
  for (auto el : arr) {
    cout << el << " ";
  }
  cout << endl;
  cout << "Result: " << evaluatePostfix(arr) << endl;
  return 0;
}

/*
Expression: 2 3 1 * + 9 -
Result: -4
*/
