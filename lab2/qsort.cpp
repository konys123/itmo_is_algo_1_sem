#include <iostream>

void qsort(int* arr, int start, int end) {
    int l = start, r = end;
    int piv = arr[(l+r)/2];

    while (l <= r) {
        while (arr[l] < piv) {
            l++;
        }
        while (arr[r] > piv) {
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

int main() {
    int N;
    std::cin >> N;
    int arr[N];

    for (int i = 0;i<N;i++){
        std::cin >> arr[i];
    }

    qsort(arr, 0, N-1);

    for (int i = 0;i<N;i++){
        std::cout << arr[i] << ' ';
    }

    return 0;
}
