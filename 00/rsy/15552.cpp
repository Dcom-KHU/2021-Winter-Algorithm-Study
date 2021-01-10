#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num,a,b;
	cin >> num;
	int *arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		arr[i] = a + b;
	}
	for (int i = 0; i < num; i++)
		cout << arr[i] << '\n';

	delete arr;
}