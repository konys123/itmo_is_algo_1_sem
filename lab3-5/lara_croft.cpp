#include <iostream>

using namespace std;


struct Node {
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct list_1 {
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
            tail->prev = ptr;
            tail = ptr;

        }
    }

    int pop_back() {
        int ans = tail->value;
        Node *tmp = tail->next;
        delete tail;
        tail = tmp;
        return ans;
    }

    void push_front(int num) {
        Node *ptr = new Node();
        ptr->value = num;
        head = ptr;
    }

    int pop_front() {
        int ans = head->value;
        if (tail == head) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *tmp = head->prev;
            delete head;
            head = tmp;
        }
        return ans;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int weight[N];
    list_1 bag;

    for (int i = 0; i < N; ++i) {
        cin >> weight[i];
    }

    for (int i = 0; i < N; ++i) {
        if (i < M) {
            bag.push_back(weight[i]);
        } else {
            int x = bag.pop_front(), y = bag.pop_back();
            if (x < y and x < weight[i]) {
                if (y < weight[i]) {
                    bag.push_back(y);
                    bag.push_back(weight[i]);
                } else {
                    bag.push_back(weight[i]);
                    bag.push_back(y);
                }
            } else if (y < x and y < weight[i]) {
                if (x < weight[i]) {
                    bag.push_back(x);
                    bag.push_back(weight[i]);
                } else {
                    bag.push_back(weight[i]);
                    bag.push_back(x);
                }
            } else {
                if (x < y) {
                    bag.push_back(x);
                    bag.push_back(y);
                } else {
                    bag.push_back(y);
                    bag.push_back(x);
                }
            }
        }
    }

    Node *ptr = bag.head;
    while (ptr != nullptr) {
        cout << ptr->value << ' ';
        ptr = ptr->prev;
    }


    return 0;
}
