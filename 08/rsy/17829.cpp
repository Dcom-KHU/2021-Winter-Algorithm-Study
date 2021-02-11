#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1025][1025];
int Pooling(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	while (N > 1) {
		for (int i = 0; i < N; i+=2)
			for (int j = 0; j < N; j+=2)
				arr[i / 2][j / 2] = Pooling(i, j);
		N /= 2;
	}

	cout << arr[0][0];

	return 0;
}

int Pooling(int a, int b) {
	vector<int> temp;

	for (int i = a; i < a + 2; i++)
		for (int j = b; j < b + 2; j++)
			temp.push_back(arr[i][j]);
	sort(temp.begin(), temp.end());

	return temp[2];
}