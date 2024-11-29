#include <iostream>

void qsort(long long int* arr, long long int start, long long int end) {
    int l = start, r = end;
    int piv = arr[(l+r)/2];

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


int main() {
    long long int n,m,k;
    std::cin >> n >> m >> k;
    long long int coefs[n],raitiing[m],raiting_1[m];
    for (int i = 0;i < n;i++){
        std::cin >> coefs[i];
    }
    for (int i = 0;i < m;i++){
        long long int a = 0;
        for (int j = 0;j<n;j++){
            long long int x;
            std::cin >> x;
            a += x*coefs[j];
        }
        raitiing[i] = a % 1000000007;
        raiting_1[i] = a % 1000000007;
    }
    qsort(raitiing,0,m-1);

    for (int i = 0;i < m;i++){
        for (int j = 0;j < m;j++){
            if (raitiing[i] == raiting_1[j]){
                std::cout << j+1 << ' ';
                k -= 1;
            }
            if (k == 0) break;
        }
        if (k == 0) break;
    }

    return 0;
}

