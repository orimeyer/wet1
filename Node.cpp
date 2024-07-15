#include "Node.h"

// Constructor
Node::Node(int data) : data(data), next(nullptr), prev(nullptr) {}

// Getters
int Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

Node* Node::getPrev() const {
    return prev;
}

// Setters
void Node::setData(int data) {
    this->data = data;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev;
}

