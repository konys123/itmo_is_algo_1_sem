#include <iostream>

using namespace std;

bool can_place(int *chairs, int k, int min, int size) {
    int last_pos = chairs[0];
    int placed = 1;

    for (int i = 0; i < size; ++i) {
        if (chairs[i] - last_pos >= min) {
            placed++;
            last_pos = chairs[i];
        }
    }

    return placed >= k;
}

int main() {
    int N, K;
    cin >> N >> K;
    int chairs[N];
    for (int i = 0; i < N; ++i) {
        cin >> chairs[i];
    }

    int left = 1;
    int right = chairs[N - 1] - chairs[0];
    int res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_place(chairs, K, mid, N)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << res;


    return 0;
}
