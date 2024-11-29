#include <iostream>


int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    int k = n * m;
    bool massive[n+1][m+1];

    for (int i = 0; i < q; i++) {
        int e, s;
        std::cin >> e >> s;
        if (massive[s][e] != e and k >= 1) k -= 1;
        massive[s][e] = e;
    }

    std::cout << k << "\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (massive[i][j] != j) {
                std::cout << j << " " << i << "\n";
            }
        }
    }

    return 0;
}
