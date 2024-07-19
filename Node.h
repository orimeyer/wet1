#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    // Constructor
    Node(int data);
    ~Node() = default;

    Node(const Node& other);

    // Assignment Operator
    Node& operator=(const Node& other);
    
    // Getters
    int getData() const;
    Node* getNext() const;
    Node* getPrev() const;

    // Setters
    void setData(int data);
    void setNext(Node* next);
    void setPrev(Node* prev);
};

#endif // NODE_H


