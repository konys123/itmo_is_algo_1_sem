#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long int value;
    Node *l = nullptr;
    Node *r = nullptr;

    Node(long long value) { this->value = value; }
};

class Tree {
public:
    Node *root = nullptr;

    Node *del(int x) {
        return deleteNode(root, x);
    }

    void prev(int x) {
        prev_(root, x,0 ,1);
    }

    void insert(int x) {
        insert_(root, x);
    }

    void next(int x) {
        next_(root, x,0 ,1);
    }

    void exist(int x) {
        exist_1(root, x);
    }

private:

    void prev_(Node *ptr, int x, int maximum,bool check) {
        if (ptr == nullptr) {
            if (check) {
                cout << "none" << '\n';
                return;
            }
            cout << maximum << '\n';
            return;
        }
        if (ptr->value < x) {
            maximum = ptr->value;
            check = 0;
            prev_(ptr->r, x, maximum,check);
        } else {
            prev_(ptr->l, x, maximum,check);
        }
    }

    void insert_(Node *node, int x) {
        if (root == nullptr) {
            root = new Node(x);
        } else if (x < node->value) {
            if (node->l == nullptr) {
                node->l = new Node(x);
                return;
            } else {
                insert_(node->l, x);
            }
        } else if (x > node->value) {
            if (node->r == nullptr) {
                node->r = new Node(x);
                return;
            } else {
                insert_(node->r, x);
            }
        }
    }

    void next_(Node *ptr, int x, int minimum,bool check) {
        if (ptr == nullptr) {
            if (check) {
                cout << "none" << '\n';
                return;
            }
            cout << minimum << '\n';
            return;
        }
        if (ptr->value > x) {
            minimum = ptr->value;
            check = 0;
            next_(ptr->l, x, minimum,check);
        } else {
            next_(ptr->r, x, minimum,check);
        }
    }

    void exist_1(Node *ptr, long long x) {
        if (ptr == nullptr) {
            cout << "false" << '\n';
            return;
        }
        if (ptr->value == x) {
            cout << "true" << '\n';
            return;
        }
        if (ptr->value < x) {
            exist_1(ptr->r, x);
        } else {
            exist_1(ptr->l, x);
        }
    }

    Node *minimum(Node *ptr) {
        while (ptr and ptr->l != nullptr) {
            ptr = ptr->l;
        }
        return ptr;
    }

    Node *deleteNode(Node *ptr, int x) {

        if (ptr == nullptr) return ptr;

        if (x < ptr->value)
            ptr->l = deleteNode(ptr->l, x);
        else if (x > ptr->value)
            ptr->r = deleteNode(ptr->r, x);
        else {
            if (ptr->l == nullptr) {
                Node *temp = ptr->r;
                if (ptr == root) {
                    root = nullptr;
                }
                delete ptr;
                return temp;
            } else if (ptr->r == nullptr) {
                Node *temp = ptr->l;
                delete ptr;
                return temp;
            }

            Node *temp = minimum(ptr->r);

            ptr->value = temp->value;

            ptr->r = deleteNode(ptr->r, temp->value);
        }
        return ptr;
    }

};

int main() {
    Tree t;
    for (int i = 0; i < 100; ++i) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            int x;
            cin >> x;
            t.insert(x);
        } else if (operation == "exists") {
            int x;
            cin >> x;
            t.exist(x);
        } else if (operation == "next") {
            int x;
            cin >> x;
            t.next(x);
        } else if (operation == "prev") {
            int x;
            cin >> x;
            t.prev(x);
        } else if (operation == "delete") {
            int x;
            cin >> x;
            t.root = t.del(x);
        }
    }

    return 0;
}
