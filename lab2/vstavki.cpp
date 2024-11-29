#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int arr[N];

    for (int i = 0;i<N;i++){
        std::cin >> arr[i];
    }

    for (int i = 1;i<N;i++){
        int j = i-1, key = arr[i];
        while (j>=0 and arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for (int i = 0;i<N;i++) std::cout << arr[i] << ' ';

    return 0;
}
