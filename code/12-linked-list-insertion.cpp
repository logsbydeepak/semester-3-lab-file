#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void insertBeginning(Node *&head, int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = head;
  head = newNode;
}

void insertLast(Node *&head, int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAtPosition(Node *&head, int value, int pos) {
  Node *newNode = new Node;
  newNode->data = value;

  if (pos == 1) {
    newNode->next = head;
    head = newNode;
    return;
  }

  Node *temp = head;
  for (int i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    cout << "Invalid Position!" << endl;
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void display(Node *head) {
  cout << "Linked List: ";
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node *head = NULL;

  insertBeginning(head, 30);
  insertBeginning(head, 20);
  insertBeginning(head, 10);
  display(head);

  insertLast(head, 40);
  insertLast(head, 50);
  display(head);

  insertAtPosition(head, 25, 3);
  display(head);

  return 0;
}
/*
Linked List: 10 -> 20 -> 30 -> NULL
Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Linked List: 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> NULL
*/