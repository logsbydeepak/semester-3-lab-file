#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void deleteBeginning(Node *&head) {
  if (head == NULL) {
    cout << "List is Empty!" << endl;
    return;
  }

  Node *temp = head;
  head = head->next;
  cout << temp->data << " deleted" << endl;
  delete temp;
}

void deleteLast(Node *&head) {
  if (head == NULL) {
    cout << "List is Empty!" << endl;
    return;
  }

  if (head->next == NULL) {
    cout << head->data << " deleted" << endl;
    delete head;
    head = NULL;
    return;
  }

  Node *temp = head;
  Node *prev = NULL;

  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  cout << temp->data << " deleted" << endl;
  prev->next = NULL;
  delete temp;
}

void deleteAtPosition(Node *&head, int pos) {
  if (head == NULL) {
    cout << "List is Empty!" << endl;
    return;
  }

  if (pos == 1) {
    deleteBeginning(head);
    return;
  }

  Node *temp = head;
  Node *prev = NULL;

  for (int i = 1; i < pos && temp != NULL; i++) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    cout << "Invalid Position!" << endl;
    return;
  }

  cout << temp->data << " deleted" << endl;
  prev->next = temp->next;
  delete temp;
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

  head = new Node{10, NULL};
  head->next = new Node{20, NULL};
  head->next->next = new Node{30, NULL};
  head->next->next->next = new Node{40, NULL};
  head->next->next->next->next = new Node{50, NULL};

  display(head);

  deleteBeginning(head);
  display(head);

  deleteLast(head);
  display(head);

  deleteAtPosition(head, 2);
  display(head);

  return 0;
}
/*
Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
10 deleted
Linked List: 20 -> 30 -> 40 -> 50 -> NULL
50 deleted
Linked List: 20 -> 30 -> 40 -> NULL
30 deleted
Linked List: 20 -> 40 -> NULL
*/
