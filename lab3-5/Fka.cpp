#include <iostream>
#include <vector>

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    list_1 difficult;
    vector<int> waiting_days(n,-1);
    vector<int> dif(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        dif[i] = x;
        difficult.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        while (difficult.head!= nullptr and difficult.tail->value < dif[i]){
            int prev_day = difficult.pop_back();
            waiting_days[prev_day] = i - prev_day;
        }
        difficult.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << waiting_days[i] << ' ';
    }

    return 0;
}