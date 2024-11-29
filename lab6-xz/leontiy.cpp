#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    long long id;
    long long account;

    Node *l = nullptr;
    Node *r = nullptr;

    Node(long long account, long long id) { this->account = account, this->id = id; }
};

class Tree {
public:
    Node *root = nullptr;

    void inorder(vector<long long >& arr) {
        inorder_traversal(root, arr);
    }

    Node *del(long long id, long long account) {
        return deleteNode(root, id, account);
    }

    void insert(long long account, long long id) {
        insert_(root, account, id);
    }


private:

    void inorder_traversal(Node *ptr, vector<long long >& arr) {
        if (ptr == nullptr) {
            return;
        }

        inorder_traversal(ptr->l, arr);
        arr.push_back(ptr->id);
        inorder_traversal(ptr->r, arr);
    }

    void insert_(Node *&node, long long account, long long id) {
        if (node == nullptr) {
            node = new Node(account, id);
        } else if (id < node->id) {
            if (node->l == nullptr) {
                node->l = new Node(account, id);
                return;
            } else {
                insert_(node->l, account, id);
            }
        } else if (id > node->id) {
            if (node->r == nullptr) {
                node->r = new Node(account, id);
                return;
            } else {
                insert_(node->r, account, id);
            }
        }
    }

    Node *minimum(Node *ptr) {
        while (ptr and ptr->l != nullptr) {
            ptr = ptr->l;
        }
        return ptr;
    }

    Node *deleteNode(Node *ptr, long long id, long long account) {

        if (ptr == nullptr) return ptr;

        if (id < ptr->id)
            ptr->l = deleteNode(ptr->l, id, account);
        else if (id > ptr->id)
            ptr->r = deleteNode(ptr->r, id, account);
        else if (ptr->account == account) {
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

            ptr->id = temp->id;
            ptr->account = temp->account;
            ptr->r = deleteNode(ptr->r, temp->id, temp->account);
        }
        return ptr;
    }

};

int main() {
    Tree t;
    int n;
    cin >> n;
    string command;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "buy") {
            long long account, id;
            cin >> account >> id;
            t.insert(account, id);
        } else if (command == "sell") {
            long long account, id;
            cin >> account >> id;
            t.root = t.del(id, account);
        } else if (command == "merge") {
            vector<long long> arr;
            t.inorder(arr);
            if (!arr.empty()) {
                for (int j = 0; j < arr.size() - 1; ++j) {
                    cout << arr[j] << ' ';
                }
                cout << arr[arr.size() - 1];
            }
            cout << '\n';
        }
    }
    return 0;
}
