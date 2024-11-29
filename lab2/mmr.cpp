#include <iostream>


int mergeSort(int *a, int *tmp, int l, int r) {
    int k = 0;
    if (l >= r) return 0;
    int m = l + (r - l) / 2;

    mergeSort(a, tmp, l, m);
    mergeSort(a, tmp, m + 1, r);

    for (int i = l; i <= r; i++)
        tmp[i] = a[i];

    int ai = l, bi = m + 1;

    for (int i = l; i <= r; i++) {
        if (bi > r or ai <= m and tmp[ai] < tmp[bi]) {
            a[i] = tmp[ai++];
        } else {
            k += (m - l + 1 - ai);
            a[i] = tmp[bi++];
        }
    }
    return k;
}


int main() {
    int n;
    std::cin >> n;
    int arr[n], tmp[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int ans;
    ans = mergeSort(arr, tmp, 0, n - 1);

    std::cout << ans;

    return 0;
}
