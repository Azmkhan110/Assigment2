#ifndef DEQUE_H  // Makes sure this file is not used twice by mistake
#define DEQUE_H

#include <iostream>
#include <stdexcept>

// A queue where we can add and remove customers from both sides
class Deque {
private:
    // A small box (node) to hold a customer’s number
    struct Node {
        int data;   // Customer's number
        Node* prev; // Points to the customer before
        Node* next; // Points to the customer after

        // When we make a new customer, we give them a number
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;  // First customer in line
    Node* tail;  // Last customer in line
    int count;   // How many customers are in the queue

public:
    Deque();   // Makes an empty queue
    ~Deque();  // Deletes everything when done

    bool isEmpty();     // Checks if queue is empty
    int size();         // Tells how many customers are in queue
    void pushLeft(int item);  // Adds customer to the front
    void pushRight(int item); // Adds customer to the back
    int popLeft();      // Removes the first customer
    int popRight();     // Removes the last customer
    void display();     // Shows all customers in line
};

#endif  // End of file
