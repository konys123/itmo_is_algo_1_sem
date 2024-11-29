#include <iostream>
#include <math.h>

int main() {

    int n, k;
    std::cin >> n >> k;
    int A, B, C, a1, a2, arr[n];
    std::cin >> A >> B >> C >> a1 >> a2;
    arr[0] = a1;
    arr[1] = a2;
    int ans[k],j=0,min=3;
    for (int i = 2; i < n; i++) {
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
        if (arr[i] > min){
            ans[j] = arr[i];
        }
    }




    return 0;
}