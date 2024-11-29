#include <iostream>

using namespace std;

void count_sort(char *arr,int n,int exp) {
    int output[n];
    int i, count[26] = { 0 };


    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;


    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

}

void radix_sort(char *arr, int k, int n) {
    for (int i = 0; i < k; i++) {
        count_sort(arr, n,i);
    }
}

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    return 0;
}
