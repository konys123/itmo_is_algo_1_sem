#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node *l = nullptr;
    Node *r = nullptr;

    Node(string value) { this->value = value; }
};

class Tree {
public:
    Node *root = nullptr;

    void insert(string x) {
        insert_(root, x);
    }

    bool exist(string x) {
        return exist_1(root, x);
    }

private:
    void insert_(Node *node, string x) {
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

    bool exist_1(Node *ptr, string x) {
        if (ptr == nullptr) {
            return false;
        }
        if (ptr->value == x) {
            return true;
        }
        if (ptr->value < x) {
            return exist_1(ptr->r, x);
        } else {
            return exist_1(ptr->l, x);
        }
    }


};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Tree first, second, third;
    int n;
    cin >> n;
    string arr_1[n], arr_2[n], arr_3[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr_1[i];
        first.insert(arr_1[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr_2[i];
        second.insert(arr_2[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr_3[i];
        third.insert(arr_3[i]);
    }

    int ans[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i) {
        if (!(second.exist(arr_1[i]) or third.exist(arr_1[i]))) {
            ans[0] += 3;
        } else if ((second.exist(arr_1[i]) and !(third.exist(arr_1[i]))) or
                   (!(second.exist(arr_1[i])) and third.exist(arr_1[i]))) {
            ans[0] += 1;

        }
    }

    for (int i = 0; i < n; ++i) {
        if (!(first.exist(arr_2[i]) or third.exist(arr_2[i]))) {
            ans[1] += 3;
        } else if ((first.exist(arr_2[i]) and !(third.exist(arr_2[i]))) or
                   (!(first.exist(arr_2[i])) and third.exist(arr_2[i]))) {
            ans[1] += 1;

        }
    }

    for (int i = 0; i < n; ++i) {
        if (!(second.exist(arr_3[i]) or first.exist(arr_3[i]))) {
            ans[2] += 3;
        } else if ((second.exist(arr_3[i]) and !(first.exist(arr_3[i]))) or
                   (!(second.exist(arr_3[i])) and first.exist(arr_3[i]))) {
            ans[2] += 1;

        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

    return 0;
}
