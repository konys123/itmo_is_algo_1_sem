#include <iostream>
#include <vector>

using namespace std;

vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    int limit = 100;
    vector<int> primeNumbers = generatePrimes(limit);
    for (int i = 0; i < primeNumbers.size(); ++i) {
        cout << primeNumbers[i] << ' ';
    }

    return 0;
}