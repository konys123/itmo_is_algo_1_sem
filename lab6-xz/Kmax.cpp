#include <iostream>

using namespace std;

struct Node {
    long long value;
    int count;
    Node *left, *right;

    Node(long long val) : value(val), count(1), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node *root = nullptr;


    void insert(long long value) {
        root = insert(root, value);
    }

    void del(long long value) {
        root = del(root, value);
    }

    long long KMax(int k) {
        return KMax(root, k);
    }

private:
    Node *insert(Node *node, long long value) {
        if (!node) return new Node(value);

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        node->count = 1 + getCount(node->left) + getCount(node->right);
        return node;
    }

    Node *del(Node *node, long long value) {
        if (!node) return nullptr;

        if (value < node->value) {
            node->left = del(node->left, value);
        } else if (value > node->value) {
            node->right = del(node->right, value);
        } else {

            if (!node->left or !node->right) {
                Node *temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }

            Node *temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = del(node->right, temp->value);
        }

        node->count = 1 + getCount(node->left) + getCount(node->right);
        return node;
    }

    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current and current->left) {
            current = current->left;
        }
        return current;
    }

    long long KMax(Node *node, int k) {

        int rightCount = getCount(node->right);
        if (k <= rightCount) {
            return KMax(node->right, k);
        } else if (k == rightCount + 1) {
            return node->value;
        } else {
            return KMax(node->left, k - rightCount - 1);
        }
    }

    int getCount(Node *node) {
        return node ? node->count : 0;
    }
};

int main() {
    int n, command;
    long long k;
    cin >> n;
    Tree t;

    for (int i = 0; i < n; ++i) {
        cin >> command >> k;
        if (command == -1) {
            t.del(k);
        } else if (command == 0) {
            cout << t.KMax(k) << '\n';
        } else if (command == 1) {
            t.insert(k);
        }
    }

    return 0;
}
