#include <iostream>
using namespace std;

void enqueue(int q[], int &front, int &rear, int max, int x) {
  if (rear == max - 1) {
    cout << "Queue Overflow!" << endl;
  } else {
    if (front == -1)
      front = 0;
    q[++rear] = x;
    cout << x << " inserted" << endl;
  }
}

void dequeue(int q[], int &front, int &rear) {
  if (front == -1 || front > rear) {
    cout << "Queue Underflow!" << endl;
  } else {
    cout << q[front] << " deleted" << endl;
    front++;
  }
}

void display(int q[], int front, int rear) {
  if (front == -1 || front > rear) {
    cout << "Queue is Empty!" << endl;
  } else {
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
      cout << q[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  int max = 5;
  int queue[max];
  int front = -1, rear = -1;

  enqueue(queue, front, rear, max, 10);
  enqueue(queue, front, rear, max, 20);
  enqueue(queue, front, rear, max, 30);

  display(queue, front, rear);

  dequeue(queue, front, rear);
  display(queue, front, rear);

  enqueue(queue, front, rear, max, 40);
  enqueue(queue, front, rear, max, 50);

  display(queue, front, rear);

  return 0;
}
/*
10 inserted
20 inserted
30 inserted
Queue elements: 10 20 30
10 deleted
Queue elements: 20 30
40 inserted
50 inserted
Queue elements: 20 30 40 50
*/
