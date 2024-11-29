#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    long long value;
    Node *l = nullptr;
    Node *r = nullptr;

    Node(long long value) { this->value = value; }
};

class Tree {
public:
    Node *root = nullptr;

    Node *build(vector<long long> &pre) {
        return build_(pre);
    }

    void postorder(vector<long long> &arr) {
        postorder_traversal(root, arr);
    }

    void inorder(vector<long long> &arr) {
        inorder_traversal(root, arr);
    }

private:
    Node *build_(const vector<long long> &preorder) {
        if (preorder.empty()) return nullptr;

        root = new Node(preorder[0]);
        stack<Node *> stack;
        stack.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            Node *node = nullptr;
            Node *child = new Node(preorder[i]);

            while (!stack.empty() and stack.top()->value <= preorder[i]) {
                node = stack.top();
                stack.pop();
            }

            if (node) {
                node->r = child;
            } else {
                stack.top()->l = child;
            }

            stack.push(child);
        }

        return root;
    }


    void inorder_traversal(Node *ptr, vector<long long> &arr) {
        if (ptr != nullptr) {
            inorder_traversal(ptr->l, arr);
            arr.push_back(ptr->value);
            inorder_traversal(ptr->r, arr);
        }
    }

    void postorder_traversal(Node *ptr, vector<long long> &arr) {
        if (ptr != nullptr) {
            postorder_traversal(ptr->l, arr);
            postorder_traversal(ptr->r, arr);
            arr.push_back(ptr->value);
        }
    };
};

int main() {
    Tree t;
    vector<long long> arr_2, arr_3;
    int n;
    cin >> n;
    vector<long long> pre(n), in(n), post(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }

    t.root = t.build(pre);

    t.inorder(arr_2);
    t.postorder(arr_3);

    if (in == arr_2 and post == arr_3) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}