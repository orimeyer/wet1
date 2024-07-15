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
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

// Check the number at the head of the queue without removing it
int Queue::peek() const {
    return head->getData();
}

// Remove the node from the head of the queue
void Queue::dequeue() {
    if (isEmpty()) {
        return; // Do nothing if the queue is empty
    }
    Node* temp = head;
    head = head->getNext();
    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->setPrev(nullptr);
    }
    delete temp;
}

// Remove a node given its pointer
void Queue::removeNode(Node* node) {
    if (isEmpty() || node == nullptr) {
        return; // Do nothing if the queue is empty or node is null
    }

    if (node == head) {
        dequeue(); // If the node to remove is the head, use dequeue
        return;
    }

    if (node == tail) {
        tail = node->getPrev();
        tail->setNext(nullptr);
        delete node;
        return;
    }

    Node* prevNode = node->getPrev();
    Node* nextNode = node->getNext();

    if (prevNode != nullptr) {
        prevNode->setNext(nextNode);
    }

    if (nextNode != nullptr) {
        nextNode->setPrev(prevNode);
    }

    delete node;
}

// Check if the queue is empty
bool Queue::isEmpty() const {
    return head == nullptr;
}

// Return the tail node
Node* Queue::getTail() const {
    return tail;
}
