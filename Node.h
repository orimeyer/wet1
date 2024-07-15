#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* next;

public:
    // Constructor
    Node(int data);

    // Getters
    int getData() const;
    Node* getNext() const;

    // Setters
    void setData(int data);
    void setNext(Node* next);
};

#endif // NODE_H

