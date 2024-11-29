#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}


bool is_simple(long long x) {
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


struct Heap {
    vector<int > h;

    void heapify(vector<int> &arr, int  i) {
        long long size = arr.size();

        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] < arr[largest]) {
            largest = l;
        }


        if (r < size && arr[r] < arr[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, largest);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int n;
    cin >> n;
    vector<int> arr_1 = generatePrimes(pow(2,n));
    vector<int> ans;
    Heap H;
    for (int i = 0; i < n; ++i) {
        H.h.push_back(arr_1[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (sqrt(H.h[0]) != round(sqrt(H.h[0]))) {
            ans.push_back(H.h[0]);
            H.h[0] = H.h[0] * H.h[0];
        } else {
            int k = 1;
            int x = H.h[0];
            H.h[0] = H.h[0] * H.h[0];
            while (sqrt(x) == round(sqrt(x))) {
                x = sqrt(x);
                k++;
            }
            for (int j = 0; j < k; ++j) {
                ans.push_back(x);
            }
        }
        H.heapify(H.h, 0);
    }

    std::sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}