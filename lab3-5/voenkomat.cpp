#include <iostream>

struct Node {
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;
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
        }
        else {
            ptr->next = tail;
            tail->prev = ptr;
            tail = ptr;

        }
    }

    void pop_back() {
        std::cout << tail->value << '\n';
        Node *tmp = tail->next;
        delete tail;
        tail = tmp;
    }

    void push_front(int num) {
        Node *ptr = new Node();
        ptr->value = num;
        head = ptr;
    }

    void pop_front() {
        std::cout << head->value << '\n';
        if (tail == head){
            delete head;
            head = nullptr;
        } else {
            Node* tmp = head->prev;
            delete head;
            head = tmp;
        }
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
        int num;
        std::cin >> sign;
        if (sign == '+') {
            std::cin >> num;
            a.push_back(num);
        }
        else if (sign == '-') {
            a.pop_front();
        }
    }


    return 0;
}
