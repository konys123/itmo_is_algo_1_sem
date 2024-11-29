#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
public:
    vector<vector<long long >> queues;

    void sift_up(vector<long long > &arr, long long int index) {
        while (index > 0) {
            long long int parent = (index - 1) / 2;
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapify(vector<long long > &arr, long long i) {
        long long size = arr.size();

        long long int largest = i;
        long long int l = 2 * i + 1;
        long long int r = 2 * i + 2;
        if (l < size && arr[l] < arr[largest])
            largest = l;
        if (r < size && arr[r] < arr[largest])
            largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, largest);
        }
    }

    void create() {
        queues.emplace_back();
    }

    void insert(long long k, long long x) {
        queues[k].push_back(x);
        sift_up(queues[k], queues[k].size() - 1);
    }

    void extract_min(long long k) {
        if (!queues[k].empty()) {
            long long min = queues[k][0];
            swap(queues[k][0], queues[k].back());
            queues[k].pop_back();
            heapify(queues[k], 0);
            cout << min << '\n';
        } else {
            cout << '*' << '\n';
        }
    }

    void decrease_key(long long int k, long long int x, long long int y) {
        for (int i = 0; i <= queues[k].size() - 1; ++i) {
            if (queues[k][i] == x) {
                queues[k][i] = y;
                break;
            }
        }
        for (int i = queues[k].size() / 2; i >= 0; --i) {
            heapify(queues[k], i);
        }
    }

    void merge(long long int k, long long int m) {
        create();
        long long int s = queues.size() - 1;
        if (!queues[k].empty()) {
            for (long long int i = 0; i < queues[k].size(); ++i) {
                queues[s].push_back(queues[k][i]);
            }
        }
        if (!queues[m].empty()) {
            for (long long int i = 0; i < queues[m].size(); ++i) {
                queues[s].push_back(queues[m][i]);
            }
        }
        if (!queues[s].empty()) {
            for (long long int i = (queues[s].size() - 1) / 2; i >= 0; --i) {
                heapify(queues[s], i);
            }
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    PriorityQueue a;
    while (cin) {
        string command;
        cin >> command;
        if (command == "create") {
            a.create();
        } else if (command == "insert") {
            long long k, x;
            cin >> k >> x;
            a.insert(k, x);
        } else if (command == "extract-min") {
            long long k;
            cin >> k;
            a.extract_min(k);
        } else if (command == "merge") {
            long long k, m;
            cin >> k >> m;
            a.merge(k, m);
        } else if (command == "decrease-key") {
            long long k, x, y;
            cin >> k >> x >> y;
            a.decrease_key(k, x, y);
        }
    }
    return 0;
}