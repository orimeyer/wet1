#ifndef HEAP_H
#define HEAP_H

#include "AVLNode.h"

template <typename K, typename T>
class Heap {
private:
    struct HeapNode {
        AVLNode<K, T>* data;
        HeapNode* next;

        HeapNode(AVLNode<K, T>* node) : data(node), next(nullptr) {}
    };

    HeapNode* head;
    int size;

    void heapify(HeapNode* root); // Helper method to heapify the heap

public:
    Heap();                     // Constructor
    ~Heap();                    // Destructor

    void insert(AVLNode<K, T>* node);   // Insert a node into the heap
    AVLNode<K, T>* remove();           // Remove and return the node at the head of the heap

    bool isEmpty() const;       // Check if the heap is empty
};

#endif // HEAP_H
