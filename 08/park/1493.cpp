#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

long long length, width, height;
int n;
int result = 0;
pair<int, int> cube[20];
bool check = true;


void func(int x, int y, int z, int i) {  // x, y, z: 남은 부분의 사이즈, ㅑ: 제일 큰 큐브
	if (i < 0) {
		if ((long long)x * y * z > 0)
			check = false;
		return;
	}

	int& len = cube[i].first;
	int& count = cube[i].second;

	if (len > x || len > y || len > z || count == 0) {  // 큐브가 크거나, 카운트가 없거나
		func(x, y, z, i - 1);
		return;
	}

	count--;
	result++;

	func(x - len, y, z, i);  // 남은 부분 3등분
	func(len, len, z - len, i);
	func(len, y - len, z, i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> length >> width >> height;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cube[i].first = pow(2, a);  // 길이 저장
		cube[i].second = b;
	}

	func(length, width, height, n - 1);  // x, y, z 크기 남음, 큰 큐브부터 시작

	if (check) {
		cout << result << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}