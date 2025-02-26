#include "Deque.h"

using namespace std;

// Set up an empty queue
Deque::Deque() : head(nullptr), tail(nullptr), count(0) {}

// Delete everything when we're done
Deque::~Deque() {
    while(head) { // Keep going until nothing is left
        Node* temp = head; // Save the first customer
        head = head->next; // Move to the next customer
        delete temp; // Remove the saved one
    }
}

// Check if the queue has no customers
bool Deque::isEmpty() { return count == 0; }

// Count how many customers are waiting
int Deque::size() { return count; }

// Add a customer to the front of the queue
void Deque::pushLeft(int item) {
    Node* newNode = new Node(item); // Make a new customer
    if(isEmpty()) { // If no one is waiting
        head = tail = newNode; // This is the only customer
    } else {
        newNode->next = head; // Link new customer to first one
        head->prev = newNode; // Link first customer to new one
        head = newNode; // Move head to the new customer
    }
    count++; // Increase customer count
}

// Add a customer to the end of the queue
void Deque::pushRight(int item) {
    Node* newNode = new Node(item); // Make a new customer
    if(isEmpty()) { // If no one is waiting
        head = tail = newNode; // This is the only customer
    } else {
        tail->next = newNode; // Link last customer to new one
        newNode->prev = tail; // Link new one to last customer
        tail = newNode; // Move tail to the new customer
    }
    count++; // Increase customer count
}

// Remove a customer from the front
int Deque::popLeft() {
    if(isEmpty()) throw runtime_error("Deque is empty"); // No customers

    int data = head->data; // Get first customer's number
    Node* temp = head; // Save first customer
    head = head->next; // Move head to next customer
    if(head) head->prev = nullptr; // Remove link to old first
    else tail = nullptr; // If no one left, tail is also empty

    delete temp; // Remove the old first customer
    count--; // Reduce customer count
    return data; // Give back customer number
}

// Remove a customer from the end
int Deque::popRight() {
    if(isEmpty()) throw runtime_error("Deque is empty"); // No customers

    int data = tail->data; // Get last customer's number
    Node* temp = tail; // Save last customer
    tail = tail->prev; // Move tail to the one before
    if(tail) tail->next = nullptr; // Remove link to old last
    else head = nullptr; // If no one left, head is also empty

    delete temp; // Remove the old last customer
    count--; // Reduce customer count
    return data; // Give back customer number
}

// Show all customers in line
void Deque::display() {
    Node* current = head; // Start from first customer
    cout << "Deque: [ ";
    while(current) { // Keep going until no customers left
        cout << current->data << " "; // Show customer number
        current = current->next; // Move to next customer
    }
    cout << "]" << endl;
}
