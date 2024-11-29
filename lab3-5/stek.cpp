#include <iostream>

struct Node {
    int value;
    Node *next = nullptr;
};

struct list {
    Node *head = nullptr;
    Node *tail = nullptr;

    void push_back(int num) {
        Node *ptr = new Node();
        ptr->value = num;
        if (head == nullptr) {
            head = ptr;
            tail = ptr;
        } else {
            ptr->next = tail;
            tail = ptr;
        }
    }

    void pop() {
        std::cout << tail->value << '\n';
        Node *tmp = tail->next;
        delete tail;
        tail = tmp;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    list a;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char sign;
        int value = 0;
        std::cin >> sign;
        if (sign == '+') {
            std::cin >> value;
            a.push_back(value);
        }
        else if (sign == '-') {
            a.pop();
        }
    }

    return 0;
}
