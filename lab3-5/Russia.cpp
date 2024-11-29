#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    long long code;
    long long raiting;
    long long gonorar;
};

struct Heap {
    vector<Node> h;

    void push_back(Node x) {
        h.push_back(x);
    }

    void heapify_raiting(vector<Node> &arr, long long i) {
        long long size = arr.size();

        long long int largest = i;
        long long int l = 2 * i + 1;
        long long int r = 2 * i + 2;
        if (l < size && arr[l].raiting >= arr[largest].raiting) {
            if (arr[l].raiting == arr[largest].raiting) {
                if (arr[l].code > arr[largest].code) {
                    largest = l;
                }
            }
            else {
                largest = l;
            }
        }
        if (r < size && arr[r].raiting >= arr[largest].raiting) {
            if (arr[r].raiting == arr[largest].raiting) {
                if (arr[r].code > arr[largest].code) {
                    largest = r;
                }
            }
            else {
                largest = r;
            }
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify_raiting(arr, largest);
        }
    }

    void heapify_gonorar(vector<Node> &arr, long long i) {
        long long size = arr.size();

        long long int largest = i;
        long long int l = 2 * i + 1;
        long long int r = 2 * i + 2;
        if (l < size && arr[l].gonorar >= arr[largest].gonorar) {
            if (arr[l].gonorar == arr[largest].gonorar) {
                if (arr[l].code > arr[largest].code) {
                    largest = l;
                }
            } else {
                largest = l;
            }
        }
        if (r < size && arr[r].gonorar >= arr[largest].gonorar) {
            if (arr[r].gonorar == arr[largest].gonorar) {
                if (arr[r].code > arr[largest].code) {
                    largest = r;
                }
            } else {
                largest = r;
            }
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify_gonorar(arr, largest);
        }
    }

    void extract_max_raiting() {
        if (!h.empty()) {
            swap(h[0], h.back());
            h.pop_back();
            heapify_raiting(h, 0);
        }
    }

    void extract_max_gonorar() {
        if (!h.empty()) {
            swap(h[0], h.back());
            h.pop_back();
            heapify_gonorar(h, 0);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int n;
    Heap max_raiting, max_gonorar;
    cin >> n;

    for (long long int i = 0; i < n; ++i) {
        Node x;
        cin >> x.code >> x.raiting >> x.gonorar;
        max_raiting.push_back(x);
        max_gonorar.push_back(x);
    }
    for (long long int i = n / 2; i >= 0; --i) {
        max_gonorar.heapify_gonorar(max_gonorar.h, i);
        max_raiting.heapify_raiting(max_raiting.h, i);
    }

    long long int m, k = 0;
    cin >> m;
    string answers[m];
    for (long long int i = 0; i < m; ++i) {
        cin >> answers[i];
    }

    vector<long long> a;
    vector<long long> b;

    for (long long int i = 0; i < n; ++i) {
        if (!max_gonorar.h.empty() and max_gonorar.h[0].code == max_raiting.h[0].code) {
            a.push_back(max_gonorar.h[0].code);
            max_gonorar.extract_max_gonorar();
            max_raiting.extract_max_raiting();
        }
        else {
            if (k < m and answers[k] == "YES") {
                a.push_back(max_raiting.h[0].code);
                b.push_back(max_raiting.h[0].code);
            } else if (k < m and answers[k] == "NO") {
                b.push_back(max_raiting.h[0].code);
            }
            k += 1;
            max_raiting.extract_max_raiting();
        }

    }

    for (long long int i = 0; i < b.size(); ++i) {
        cout << b[i] << ' ';
    }

    cout << '\n';

    for (long long int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}