#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

#endif // NODE_H
