#ifndef AVL_NODE_H
#define AVL_NODE_H

template <typename K, typename T>
class AVLNode {
public:
    // Constructor
    AVLNode(const K& k, const T& d) : key(k), data(new T(d)), left(nullptr), right(nullptr), height(1) {}

    // Copy Constructor
    AVLNode(const AVLNode& other) : key(other.key), data(new T(*(other.data))), left(nullptr), right(nullptr), height(other.height) {
        if (other.left != nullptr) {
            left = new AVLNode(*other.left);
        }
        if (other.right != nullptr) {
            right = new AVLNode(*other.right);
        }
    }

    // Assignment Operator
    AVLNode& operator=(const AVLNode& other) {
        if (this != &other) {
            key = other.key;
            *data = *(other.data);
            height = other.height;
            
            // Recursively copy left and right nodes
            if (left != nullptr) {
                delete left;
            }
            if (other.left != nullptr) {
                left = new AVLNode(*other.left);
            } else {
                left = nullptr;
            }
            
            if (right != nullptr) {
                delete right;
            }
            if (other.right != nullptr) {
                right = new AVLNode(*other.right);
            } else {
                right = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    ~AVLNode() {
        delete data;
        delete left;
        delete right;
    }

    // Getters
    K getKey() const {
        return key;
    }

    T* getData() const {
        return data;
    }

    AVLNode* getLeft() const {
        return left;
    }

    AVLNode* getRight() const {
        return right;
    }

    int getHeight() const {
        return height;
    }

    // Setters
    void setKey(const K& newKey) {
        key = newKey;
    }

    void setData(T* newData) {
        data = newData;
    }

    void setLeft(AVLNode* newLeft) {
        left = newLeft;
    }

    void setRight(AVLNode* newRight) {
        right = newRight;
    }

    void setHeight(int newHeight) {
        height = newHeight;
    }

private:
    K key;
    T* data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

#endif // AVL_NODE_H
