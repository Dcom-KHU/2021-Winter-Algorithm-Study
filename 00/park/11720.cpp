#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    cin >> n;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += str[i] - '0';

    cout << sum << endl;
    return 0;
}