#include <iostream>

void antiqsort(int* a,int n){

    for (int i = 2; i < n; ++i) {
        a[i] = i + 1;
        std::swap(a[i],a[i/2]);
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];

    for (int i = 0;i < n;i++){
        arr[i] = i+1;
    }

    antiqsort(arr, n);

    return 0;
}
