#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct Node {
    int value;
    int l;
    int r;
};

vector<int> heights;

int count_height(Node nodes[], int i) {
    if (i == 0)
        return 0;

    if (heights[i] == -1) {
        int leftHeight = count_height(nodes, nodes[i].l);
        int rightHeight = count_height(nodes, nodes[i].r);
        heights[i] = 1 + max(leftHeight, rightHeight);
    }

    return heights[i];
}

int count_balance(Node nodes[], int i) {
    int leftHeight = count_height(nodes, nodes[i].l);
    int rightHeight = count_height(nodes, nodes[i].r);

    return rightHeight - leftHeight;
}

int main() {
    int n;
    cin >> n;

    Node nodes[n + 1];
    heights.assign(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].value >> nodes[i].l >> nodes[i].r;
    }

    for (int i = 1; i <= n; ++i) {
        cout << count_balance(nodes, i) << '\n';
    }

    return 0;
}