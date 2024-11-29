#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long int value;
    int level;
    Node *l = nullptr;
    Node *r = nullptr;

    Node(long long value) { this->value = value; }
};

class Tree {
public:
    Node *root = nullptr;

    void reverse_preorder(vector<bool> &levels) {
        reverse_preorder_(root, levels);
    }

    void insert(int x) {
        insert_(root, x);
    }

private:

    void insert_(Node *node, int x) {
        if (root == nullptr) {
            root = new Node(x);
            root->level = 0;
        } else if (x < node->value) {
            if (node->l == nullptr) {
                node->l = new Node(x);
                node->l->level = node->level + 1;
                return;
            } else {
                insert_(node->l, x);
            }
        } else if (x > node->value) {
            if (node->r == nullptr) {
                node->r = new Node(x);
                node->r->level = node->level + 1;
                return;
            } else {
                insert_(node->r, x);
            }
        }
    }

    void reverse_preorder_(Node *ptr, vector<bool> &levels) {
        if (ptr == nullptr) {
            return;
        }
        if (!levels[ptr->level]) {
            cout << ptr->value << ' ';
            levels[ptr->level] = 1;
        }
        reverse_preorder_(ptr->r, levels);
        reverse_preorder_(ptr->l, levels);
    }

};

int main() {
    Tree t;
    int n;
    cin >> n;
    vector<bool> levels(n);
    levels.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        t.insert(x);
    }

    t.reverse_preorder(levels);

    return 0;
}
