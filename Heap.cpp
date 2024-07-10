#include "Heap.h"

template <typename K, typename T>
Heap<K, T>::Heap() : head(nullptr), size(0) {}

template <typename K, typename T>
Heap<K, T>::~Heap() {
    while (!isEmpty()) {
        remove();
    }
}

template <typename K, typename T>
void Heap<K, T>::insert(AVLNode<K, T>* node) {
    HeapNode* newNode = new HeapNode(node);

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    // Heapify up
    HeapNode* current = head;
    while (current->next != nullptr && current->data->getKey() < current->next->data->getKey()) {
        std::swap(current->data, current->next->data);
        current = current->next;
    }

    size++;
}

template <typename K, typename T>
AVLNode<K, T>* Heap<K, T>::remove() {
    if (isEmpty()) {
        return nullptr; // Handle empty heap scenario
    }

    AVLNode<K, T>* root = head->data;
    HeapNode* temp = head;
    head = head->next;
    delete temp;

    size--;

    // Heapify down
    if (head != nullptr) {
        heapify(head);
    }

    return root;
}

template <typename K, typename T>
void Heap<K, T>::heapify(HeapNode* root) {
    HeapNode* largest = root;
    HeapNode* left = root->next;
    HeapNode* right = (left != nullptr) ? left->next : nullptr;

    if (left != nullptr && left->data->getKey() > largest->data->getKey()) {
        largest = left;
    }

    if (right != nullptr && right->data->getKey() > largest->data->getKey()) {
        largest = right;
    }

    if (largest != root) {
        std::swap(root->data, largest->data);
        heapify(largest);
    }
}

template <typename K, typename T>
bool Heap<K, T>::isEmpty() const {
    return size == 0;
}

// Explicit instantiation of the template classes we need
template class Heap<int, int>; // Example instantiation; replace with your AVLNode's key and data types
