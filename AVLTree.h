#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "AVLNode.h"

template <typename K, typename T>
class AVLTree {
private:
    AVLNode<K, T>* root;
    int number_of_nodes;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(AVLNode<K, T>* node) {
        return (node == nullptr) ? 0 : node->getHeight();
    }

    int balanceFactor(AVLNode<K, T>* node) {
        return (node == nullptr) ? 0 : height(node->getLeft()) - height(node->getRight());
    }

    void updateHeight(AVLNode<K, T>* node) {
        if (node != nullptr) {
            node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
        }
    }

    AVLNode<K, T>* rotateRight(AVLNode<K, T>* y) {
        AVLNode<K, T>* x = y->getLeft();
        AVLNode<K, T>* T2 = x->getRight();

        x->setRight(y);
        y->setLeft(T2);

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode<K, T>* rotateLeft(AVLNode<K, T>* x) {
        AVLNode<K, T>* y = x->getRight();
        AVLNode<K, T>* T2 = y->getLeft();

        y->setLeft(x);
        x->setRight(T2);

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode<K, T>* minValueNode(AVLNode<K, T>* node) {
        while (node->getLeft() != nullptr) {
            node = node->getLeft();
        }
        return node;
    }

    AVLNode<K, T>* insertNode(AVLNode<K, T>* node, K key, T* data) {
        if (node == nullptr) {
            return new AVLNode<K, T>(key, *data);
        }

        if (key < node->getKey()) {
            node->setLeft(insertNode(node->getLeft(), key, data));
        } else if (key > node->getKey()) {
            node->setRight(insertNode(node->getRight(), key, data));
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->getLeft()->getKey()) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->getRight()->getKey()) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->getLeft()->getKey()) {
            node->setLeft(rotateLeft(node->getLeft()));
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->getRight()->getKey()) {
            node->setRight(rotateRight(node->getRight()));
            return rotateLeft(node);
        }
        number_of_nodes++;
        return node;
    }

    AVLNode<K, T>* removeNode(AVLNode<K, T>* root, K key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->getKey()) {
            root->setLeft(removeNode(root->getLeft(), key));
        } else if (key > root->getKey()) {
            root->setRight(removeNode(root->getRight(), key));
        } else {
            if (root->getLeft() == nullptr || root->getRight() == nullptr) {
                AVLNode<K, T>* temp = root->getLeft() ? root->getLeft() : root->getRight();
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                AVLNode<K, T>* temp = minValueNode(root->getRight());
                root->setKey(temp->getKey());
                root->setRight(removeNode(root->getRight(), temp->getKey()));
            }
        }
        if (root == nullptr) {
            return root;
        }
        updateHeight(root);

        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && balanceFactor(root->getLeft()) >= 0) {
            return rotateRight(root);
        }

        // Left Right Case
        if (balance > 1 && balanceFactor(root->getLeft()) < 0) {
            root->setLeft(rotateLeft(root->getLeft()));
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(root->getRight()) <= 0) {
            return rotateLeft(root);
        }

        // Right Left Case
        if (balance < -1 && balanceFactor(root->getRight()) > 0) {
            root->setRight(rotateRight(root->getRight()));
            return rotateLeft(root);
        }
        number_of_nodes--;
        return root;
    }

    AVLNode<K, T>* findNode(AVLNode<K, T>* node, K key) const {
        if (node == nullptr || node->getKey() == key) {
            return node;
        }
        if (key < node->getKey()) {
            return findNode(node->getLeft(), key);
        }
        return findNode(node->getRight(), key);
    }

    bool containsNode(AVLNode<K, T>* node, K key) const {
        if (node == nullptr) {
            return false;
        }

        if (key == node->getKey()) {
            return true;
        } else if (key < node->getKey()) {
            return containsNode(node->getLeft(), key);
        } else {
            return containsNode(node->getRight(), key);
        }
    }

    K getMaximumKey() const {
        AVLNode<K, T>* current = root;
        if (current == nullptr)
            throw "Tree is empty.";

        // Traverse to the rightmost node
        while (current->getRight() != nullptr) {
            current = current->getRight();
        }

        return current->getKey();
    }

    void deleteTree(AVLNode<K, T>* node) {
        if (node != nullptr) {
            deleteTree(node->getLeft());
            deleteTree(node->getRight());
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr), number_of_nodes(0) {}
    ~AVLTree(){deleteTree(root);}

    void insert(K key, T* data) {
        root = insertNode(root, key, data);
    }

    void remove(K key) {
        root = removeNode(root, key);
    }

    AVLNode<K, T>* find(K key) const {
        return findNode(root, key);
    }

    bool contains(K key) const {
        return containsNode(root, key);
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    AVLNode<K, T>* getRoot() const {
        return root;
    }

    void setRoot(AVLNode<K, T>* newRoot) {
        root = newRoot;
    }

    int getNumberOfNodes() const {
        return number_of_nodes;
    }

    K getMaxKey() const {
        return getMaximumKey();
    }
};

#endif // AVL_TREE_H
