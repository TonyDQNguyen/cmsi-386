#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Stack {

private:

    struct Node {
        T data;
        Node* next;
    };

    int size = 0;
    Node* top = nullptr;

    Node* copy(Node* n) {
        return new Node {n->data,  n->next ? copy(n->next): nullptr};
    }
public:

    ~Stack() {
        while (top != nullptr){
            pop();
        }
    }
    Stack() = default;

    //Construction
    Stack(const Stack& s) {
        size = s.size;
        top = copy(s.top);
    }

    //Assignment
    Stack& operator = (const Stack& s) {
        if (&s != this){
            while (top != nullptr) pop();
            size = s.size;
            top = copy(s.top);
        }
        return *this;
    }
    int get_size(){
        return size;
    }

    T get_top(){
        return top->data;
    }

    void push(T x) {
        top = new Node{x, top};
        size++;
    }

    T pop(){
        Node* nodeToDelete = top;
        T valueToReturn = top->data;
        top = top->next;
        size--;
        delete nodeToDelete;
        return valueToReturn;
    }
};

int main(){
    Stack<int> s;
    assert(s.get_size() == 0);
    s.push(100);
    assert(s.get_top() == 100);
    assert(s.get_size() == 1);
    s.push(200);
    assert(s.get_top() == 200);
    assert(s.get_size() == 2);

};
