#include "Node.h"

// Constructor
Node::Node(int data) : data(data), next(nullptr) {}

// Getters
int Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

// Setters
void Node::setData(int data) {
    this->data = data;
}

void Node::setNext(Node* next) {
    this->next = next;
}
