#include <iostream>
#include <string>

using namespace std;

void count_sort(int *arr, string *names, int n, int max) {
    int dictionary[max + 1];
    int n_mas_1[n];
    string n_mas_2[n];

    for (int i = 0; i < max + 1; ++i) {
        dictionary[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        dictionary[arr[i]] += 1;
    }
    for (int i = 1; i < max + 1; ++i) {
        dictionary[i] += dictionary[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        dictionary[arr[i]] -= 1;
        n_mas_1[dictionary[arr[i]]] = arr[i];
        n_mas_2[dictionary[arr[i]]] = names[i];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = n_mas_1[i];
        names[i] = n_mas_2[i];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, q, m = 0;
    cin >> n;
    int damage[n];
    string names[n];

    for (int i = 0; i < n; ++i) {
        cin >> damage[i];
        if (damage[i] > m) {
            m = damage[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    cin >> q;

    count_sort(damage, names, n, m);

    for (int i = 0; i < n; ++i) {
        cout << damage[i];
        if (i != n - 1) cout << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << names[i];
        if (i != n - 1) cout << ' ';
    }
    cout << '\n';

    int pref_sum_count[m + 1],pref_sum_sum[m+1];

    for (int i = 0; i < m + 1; ++i) {
        pref_sum_sum[i] = 0;
        pref_sum_count[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        pref_sum_count[damage[j]] += 1;
        pref_sum_sum[damage[j]] += damage[j];
    }
    for (int i = 1; i < m + 1; ++i) {
        pref_sum_count[i] += pref_sum_count[i-1];
        pref_sum_sum[i] += pref_sum_sum[i-1];
    }

    int counters_for_xor[m+1],counters[m+1];
    for (long long i = 0; i < n; i++) {
        counters[damage[i]]++;
    }
    for (long long i = 1; i < m + 1; i++) {
        counters_for_xor[i] = counters[i];
        counters[i] += counters[i - 1];
    }


    for (int i = 0; i < q; ++i) {
        string request;
        int l, r;
        cin >> request >> l >> r;
        if (r > m){
            r = m;
        }
        if (request == "Count") {
            cout << pref_sum_count[r] - pref_sum_count[l-1] << '\n';
        }

        else if (request == "Sum") {
            cout << pref_sum_sum[r] - pref_sum_sum[l-1] << '\n';
        }

        else if (request == "Xor") {
            int ans = 0;

            cout << counters[r] - counters[l-1] << '\n';
        }
    }


    return 0;
}
