#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
private:
    Node* head; // Points to the head of the queue
    Node* tail; // Points to the tail of the queue

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Insert an element at the tail of the queue
    void enqueue(int value);

    // Check the number at the head of the queue without removing it
    int peek() const;

    // Remove the node from the head of the queue
    void dequeue();

    // Remove a node given its pointer
    void removeNode(Node* node);

    // Check if the queue is empty
    bool isEmpty() const;

    // Return the tail node
    Node* getTail() const;
};

#endif // QUEUE_H
