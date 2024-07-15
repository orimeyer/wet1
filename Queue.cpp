#include "Queue.h"

// Constructor
Queue::Queue() : head(nullptr), tail(nullptr) {}

// Destructor
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Insert an element at the tail of the queue
void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Check the number at the head of the queue without removing it
int Queue::peek() const {
    return head->data;
}

// Remove the node from the head of the queue
void Queue::dequeue() {
    if (isEmpty()) {
        return; // Do nothing if the queue is empty
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
}

// Check if the queue is empty
bool Queue::isEmpty() const {
    return head == nullptr;
}
