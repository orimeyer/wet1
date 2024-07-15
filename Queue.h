#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    // Node structure for the linked list
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

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

    // Check if the queue is empty
    bool isEmpty() const;
};

#endif // QUEUE_H
