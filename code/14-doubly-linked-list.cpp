#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *prev;
  Node *next;
};

void insertEnd(Node *&head, int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->prev = NULL;
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
  newNode->prev = temp;
}

void traverse(Node *head) {
  cout << "Doubly Linked List: ";
  Node *temp = head;

  while (temp != NULL) {
    cout << temp->data << " <-> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node *head = NULL;

  insertEnd(head, 10);
  insertEnd(head, 20);
  insertEnd(head, 30);
  insertEnd(head, 40);

  traverse(head);

  return 0;
}
/*
Doubly Linked List: 10 <-> 20 <-> 30 <-> 40 <-> NULL
*/