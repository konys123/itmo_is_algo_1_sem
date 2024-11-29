#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n+1];

    for (int i = 1; i < n+1; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i < n+1; ++i) {
        if (2 * i <= n) {
            if (arr[i] > arr[2 * i]) {
                cout << "NO";
                return 0;
            }
        }
        if (2 * i + 1 <= n) {
            if (arr[i] > arr[2 * i + 1]) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}
