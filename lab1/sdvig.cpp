#include <iostream>

int main(){
    int N, K, j = 0;
    std::cin >> N >> K;
    int massive[N-1],massive_1[N-1];
    K = K%N;
    for (int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        massive[i] = x;
    }
    if (K == 0){
        for (int i = 0;i < N;i++){
            massive_1[j] = massive[i];
            j++;
        }
    }
    if (K > 0) {
        for (int i = N - K; i < N; i++) {
            massive_1[j] = massive[i];
            j++;
        }
        for (int i = 0; i <= N - K - 1; i++) {
            massive_1[j] = massive[i];
            j++;
        }
    }
    if (K < 0){
        for (int i = -K; i < N;i++){
            massive_1[j] = massive[i];
            j++;
        }
        for (int i = 0;i < -K;i++){
            massive_1[j] = massive[i];
            j++;
        }
    }

    for (int i = 0;i<N;i++) std::cout << massive_1[i] << ' ';

    return 0;
}