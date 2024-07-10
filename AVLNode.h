#ifndef AVL_NODE_H
#define AVL_NODE_H

template <typename K, typename T>
class AVLNode {
public:
    K getKey() const {
        return key;
    }

    void setKey(const K& newKey) {
        key = newKey;
    }

    T* getData() const {
        return data;
    }

    void setData(T* newData) {
        data = newData;
    }

    AVLNode* getLeft() const {
        return left;
    }

    void setLeft(AVLNode* newLeft) {
        left = newLeft;
    }

    AVLNode* getRight() const {
        return right;
    }

    void setRight(AVLNode* newRight) {
        right = newRight;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int newHeight) {
        height = newHeight;
    }

    AVLNode(const K& k, const T& d) : key(k), data(new T(d)), left(nullptr), right(nullptr), height(1) {}

    AVLNode& operator=(const AVLNode& other) {
        if (this != &other) {
            key = other.key;
            // Assuming T has a copy assignment operator or is a simple type
            *data = *(other.data);
            // Recursively copy left and right nodes
            if (other.left != nullptr) {
                left = new AVLNode(*other.left);
            } else {
                left = nullptr;
            }
            if (other.right != nullptr) {
                right = new AVLNode(*other.right);
            } else {
                right = nullptr;
            }
            height = other.height;
        }
        return *this;
    }

    ~AVLNode() {
        delete data;
    }

private:
    K key;
    T* data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

#endif // AVL_NODE_H

