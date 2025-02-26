#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

class Deque {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    Deque();
    ~Deque();

    bool isEmpty();
    int size();
    void pushLeft(int item);
    void pushRight(int item);
    int popLeft();
    int popRight();
    void display();
};

#endif