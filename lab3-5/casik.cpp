#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, ostatok = 0;
    cin >> N;
    vector<long long> a;
    string x;
    cin >> x;

    for (int i = 0; i < x.size(); ++i) {
        a[i] = x[i] - '0';
    }
    for (int i = 0; i < a.size() / 2; ++i) {
        swap(a[i], a[a.size() - i - 1]);
    }

    for (int i = 0; i < N; ++i) {
        string y;
        cin >> y;
        vector<long long> b;
        for (int j = 0; j < y.size(); ++j) {
            b[i] = y[i] - '0';
        }
        for (int j = 0; j < b.size() / 2; ++j) {
            swap(b[j], b[b.size() - j - 1]);
        }

        for (int j = 0; j < max(a.size(), b.size()); ++j) {
            if (j < a.size()) {
                if (j < b.size()) {
                    a[j] += b[j] + ostatok;
                    if (a[j] + b[j] >= 10) {
                        ostatok = 1;
                    } else {
                        ostatok = 0;
                    }
                } else {
                    a[j] += ostatok;
                    if (a[j] + ostatok >= 10) {
                        ostatok = 1;
                    } else {
                        ostatok = 0;
                    }
                }
            } else {
                a.push_back(b[j] + ostatok);
                if (b[j] + ostatok >= 10) {
                    ostatok = 1;
                } else {
                    ostatok = 0;
                }
            }

        }

    }
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}
