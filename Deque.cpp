#include "Deque.h"

using namespace std;

Deque::Deque() : head(nullptr), tail(nullptr), count(0) {}

Deque::~Deque() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool Deque::isEmpty() { return count == 0; }

int Deque::size() { return count; }

void Deque::pushLeft(int item) {
    Node* newNode = new Node(item);
    if(isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

void Deque::pushRight(int item) {
    Node* newNode = new Node(item);
    if(isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

int Deque::popLeft() {
    if(isEmpty()) throw runtime_error("Deque is empty");

    int data = head->data;
    Node* temp = head;
    head = head->next;
    if(head) head->prev = nullptr;
    else tail = nullptr;

    delete temp;
    count--;
    return data;
}

int Deque::popRight() {
    if(isEmpty()) throw runtime_error("Deque is empty");

    int data = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    if(tail) tail->next = nullptr;
    else head = nullptr;

    delete temp;
    count--;
    return data;
}

void Deque::display() {
    Node* current = head;
    cout << "Deque: [ ";
    while(current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]" << endl;
}