#include <iostream>

int main() {
    long int N,K;
    std::cin >> N >> K;
    int massive[N-1];
    K = K%N;
    for (int i = 0;i<N;i++){
        int x;
        std::cin >> x;
        if (K == 0) {
            massive[i] = x;
        }
        if (K>0) {
            if (i+K<N) massive[i + K] = x;
            else massive[i - K + 1 ] = x;
        }
        else{
            if (i+K>=0) massive[i + K] = x;
            else massive[i - K + 1] = x;
        }
    }
    for (int i = 0; i < N; ++i) {
        std::cout << massive[i] << " ";
    }
    return 0;
}