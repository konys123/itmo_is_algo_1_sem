#include <iostream>
#include <string>

using namespace std;

bool isValidBracketSequence(int n, string& brackets) {
    int balance1 = 0,balance2 = 0,balance3 = 0;

    for (int i =0 ; i < brackets.size();i++) {
        if (brackets[i] == '(') {
            balance1++;
        }
        if (brackets[i] == '[') {
            balance2++;
        }
        if (brackets[i] == '{') {
            balance3++;
        }
        if (brackets[i] == '}') {
            balance3--;
        }
        if (brackets[i] == ']') {
            balance2--;
        }
        if (brackets[i] == ')') {
            balance1--;
        }
        if (balance1 < 0 or balance2 < 0 or balance3 < 0) {
            return false;
        }
    }


    return balance1+balance2+balance3 == 0;
}

int main() {
    int n;
    cin >> n;

    string brackets;
    cin >> brackets;

    if (isValidBracketSequence(n, brackets)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}