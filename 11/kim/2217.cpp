#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100000+1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; // 로프의 개수
	int rope[SIZE];
	int max = 0; //무게 최대값
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n); //크기순서대로 정렬
	for (int i = 0; i < n; i++) {
		if (max < rope[i] * (n - i)) {
			max = rope[i] * (n - i); //제일 무게가 작은경은 경우부터 하나씩 비교
		}
	}
	cout << max;
}
