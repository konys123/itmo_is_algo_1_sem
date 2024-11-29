#include <iostream>

void qsort(long long int* arr, long long int start, long long int end) {
    long long int l = start, r = end;
    long long int piv = arr[rand() % (r - l + 1) + l];

    while (l <= r) {
        while (arr[l] > piv) {
            l++;
        }
        while (arr[r] < piv) {
            r--;
        }
        if (l <= r) {
            std::swap(arr[l++], arr[r--]);
        }
    }

    if (start < r) {
        qsort(arr, start, r);
    }
    if (end > l) {
        qsort(arr, l, end);
    }
}

long long int area_search(long long int *arr, long long int N) {
    long long int side_1 = 0, side_2 = 0, S = 0;

    for (long long int i = 0; i < N; i++) {
        if ((arr[i] == arr[i + 1] or arr[i] - 1 == arr[i + 1])) {
            if (side_1 == 0) {
                side_1 = (arr[i] + arr[i + 1]) / 2;
                i++;
            }
            else {
                side_2 = (arr[i] + arr[i + 1]) / 2;
                i++;
                S += side_2 * side_1;
                side_1 = 0;
            }
        }
    }

    return S;
}

int main() {
    long long int N, ans;
    std::cin >> N;
    long long int arr[N];

    for (long long int i = 0; i < N; i++) std::cin >> arr[i];

    qsort(arr,0, N-1);
    ans = area_search(arr, N);

    std::cout << ans;

    return 0;
}
