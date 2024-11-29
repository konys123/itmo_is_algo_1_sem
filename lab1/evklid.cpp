#include <iostream>

int main() {
    long int a,b;
    std::cin >> a >> b;
    while (a!=0 and b!=0){
        if (a > b) a = a%b;
        else b = b%a;
    }
    std::cout << a+b << "\n";
    return 0;
}