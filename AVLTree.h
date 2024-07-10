#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "AVLNode.h"

template <typename K, typename T>
class AVLTree {
private:
    AVLNode<K, T>* root;
    int number_of_nodes;

    int getHeight(AVLNode<K, T>* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalance(AVLNode<K, T>* node) {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(AVLNode<K, T>* node) {
        if (node != nullptr) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    AVLNode<K, T>* rotateRight(AVLNode<K, T>* y) {
        AVLNode<K, T>* x = y->left;
        AVLNode<K, T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode<K, T>* rotateLeft(AVLNode<K, T>* x) {
        AVLNode<K, T>* y = x->right;
        AVLNode<K, T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode<K, T>* minValueNode(AVLNode<K, T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    AVLNode<K, T>* insertNode(AVLNode<K, T>* node, K key, T* data) {
        if (node == nullptr) {
            return new AVLNode<K, T>(key, *data);
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key, data);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key, data);
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        updateHeight(node);

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        number_of_nodes++;
        return node;
    }

    AVLNode<K, T>* removeNode(AVLNode<K, T>* root, K key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = removeNode(root->left, key);
        } else if (key > root->key) {
            root->right = removeNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                AVLNode<K, T>* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                AVLNode<K, T>* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = removeNode(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        updateHeight(root);

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rotateRight(root);
        }

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0) {
            return rotateLeft(root);
        }

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        number_of_nodes--;
        return root;
    }

    AVLNode<K, T>* findNode(AVLNode<K, T>* node, K key) const {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return findNode(node->left, key);
        }
        return findNode(node->right, key);
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

public:
    AVLTree() : root(nullptr), number_of_nodes(0) {}

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
};

#endif // AVL_TREE_H
