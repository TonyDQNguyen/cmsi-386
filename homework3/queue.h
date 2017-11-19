#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Queue {

 struct Node {
    T data;
    Node* next;
  };

 int size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

 Node* copy(Node* n) {
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }

public:

 ~Queue() {
    while (head != nullptr) {
      Node *nodeToDelete = head;
      head = head->next;
      delete nodeToDelete;
    }
    tail = nullptr;
  }

 Queue() = default;

 Queue(const Queue& q) = delete;
  Queue& operator=(const Queue& q) = delete;

 Queue(Queue&& q): size(q.size), head(q.head), tail(q.tail) {
    q.head = nullptr;
    q.tail = nullptr;
    q.size = 0;
  }

 Queue& operator=(Queue&& q) {
    if (&q != this) {
      size = q.size;
      head = q.head;
      tail = q.tail;
      q.head = nullptr;
      q.tail = nullptr;
      q.size = 0;
    }
    return *this;
  }

 int get_size() {
    return size;
  }

 T get_head() {
    return head->data;
  }

 T get_tail(){
    return tail->data;
  }

 void enqueue(T x) {
    Node *nodeToInsert = new Node;
    nodeToInsert->data = x;
    nodeToInsert->next = nullptr;
    if (head == nullptr){
        head = nodeToInsert;
        tail = nodeToInsert;
    } else {
        tail->next = nodeToInsert;
        tail = nodeToInsert;
    }
    size++;
  }

 T dequeue() {
    if (size == 0)
      throw underflow_error("Your queue is already empty");
    Node* nodeToDelete = head;
    T valueToReturn = head->data;
    head = head->next;
    size--;
    delete nodeToDelete;
    return valueToReturn;
  }
};
