#include <iostream>

int main() {
    int N, sum_left = 0,sum_right = 0,s = 0;
    std::cin >> N;
    int massive[N - 1];
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        massive[i] = x;
        if (i > 0) sum_right += x;
    }
    for (int i = 0;i<N-1;i++){
        if (sum_right == sum_left){
            std::cout << i;
            s = 1;
            break;
        } else{
            sum_left += massive[i];
            sum_right -= massive[i+1];
        }
    }
    if (s == 0) std::cout << -1 << "\n";
    return 0;
}