#include <iostream>

int main() {
    int N, k = 0;
    std::cin >> N;
    char massive[N];

    for (int i = 0; i < N; i++) {
        char x;
        std::cin >> x;
        massive[i] = x;
    }

    for (int i = 0, j = N - 1; i <= j; i++, j--) {
        if (massive[i] != massive[j]) {
            k += 1;
            if (massive[i] == massive[j-1]) i--;
            else j++;
            if (k > 1) break;
        }
    }

    if (k <= 1) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}
