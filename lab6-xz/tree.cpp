#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *l = nullptr;
    Node *r = nullptr;

    Node(int value) { this->value = value; }
};

class Tree {
public:
    Node *root = nullptr;

    void preorder() {
        preorder_traversal(root);
    }

    void bild(int arr[], int l, int r) {
        bild_tree(arr,l,r,&root);
    }

private:

    void preorder_traversal(Node *ptr) {
        if (ptr != nullptr) {
            cout << ptr->value << ' ';
            preorder_traversal(ptr->l);
            preorder_traversal(ptr->r);
        }
    };

    void bild_tree(int array[], int l, int r, Node** temp) {
        if (l > r) {
            return;
        }
        int mid = l + (r - l) / 2;
        *temp = new Node(array[mid]);
        bild_tree(array, l, mid - 1, &((*temp)->l));
        bild_tree(array, mid + 1, r, &((*temp)->r));
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Tree t;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    int r = n - 1, l = 0;

    t.bild(arr,l,r);
    t.preorder();

    return 0;
}
