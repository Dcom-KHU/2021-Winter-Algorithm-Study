#include <iostream>

using namespace std;

#define MAX 100
long long int fibonacci[MAX];

int main() {
	int n;
	cin >> n;

	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	cout << fibonacci[n] << "\n";

	return 0;
}
