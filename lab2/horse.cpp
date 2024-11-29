#include <iostream>


int main() {

    int n,c = 1;
    std::cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (int j = 0;j < n-1;j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                if (arr[i] != arr[i + 1] + 1 and arr[i] > 0) {
                    std::swap(arr[i], arr[i + 1]);
                    arr[i] += 1;
                    arr[i + 1] -= 1;
                } else {
                    c = 0;
                    break;
                }
            }
        }
        if (c == 0) break;
    }
    if (c == 1) {
        for (int i = 0;i < n;i++) std::cout << arr[i]<<' ';
    } else std::cout << ":(";

    return 0;
}