#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, max = 30, min = 15;
        std::cin >> n;

        for (int j = 0; j < n; j++) {
            int value;
            char a,b;
            std::cin >> a >> b >> value;

            if (a == '>' and value <= max) {
                if (min < value) min = value;
                std::cout << min << "\n";
            } else if (a == '<' and value >= min) {
                if (max > value) max = value;
                std::cout << min << "\n";
            } else {
                max = 0;
                min = 31;
                std::cout << -1 << "\n";
            }
        }
    }

    return 0;
}