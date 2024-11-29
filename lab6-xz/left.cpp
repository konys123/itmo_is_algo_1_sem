#include <iostream>
#include <vector>

struct Node {
    int key;
    int left;
    int right;
    int height;
};

std::vector<Node> nodes;

int getHeight(int index) {
    return (index == 0) ? 0 : nodes[index].height;
}

void updateHeight(int index) {
    nodes[index].height = 1 + std::max(getHeight(nodes[index].left), getHeight(nodes[index].right));
}

int leftRotate(int rootIndex) {
    int newRootIndex = nodes[rootIndex].right;
    nodes[rootIndex].right = nodes[newRootIndex].left;
    nodes[newRootIndex].left = rootIndex;
    updateHeight(rootIndex);
    updateHeight(newRootIndex);
    return newRootIndex;
}

void updateBalances(int index) {
    updateHeight(index);
    updateHeight(nodes[index].left);
    updateHeight(nodes[index].right);
}

int main() {
    int n;
    std::cin >> n;

    nodes.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> nodes[i].key >> nodes[i].left >> nodes[i].right;
    }

    int rootIndex = 1;

    int newRootIndex = leftRotate(rootIndex);

    std::cout << nodes[newRootIndex].key << " " << nodes[newRootIndex].left << " " << nodes[newRootIndex].right << std::endl;
    for (int i = 1; i <= n; ++i) {
        if (i != newRootIndex) {
            std::cout << nodes[i].key << " " << nodes[i].left << " " << nodes[i].right << std::endl;
        }
    }

    return 0;
}