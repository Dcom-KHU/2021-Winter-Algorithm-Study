#include <iostream>
using namespace std;


int main() {
	int t;
	int n, m;
	int a, b;

	cin >> t;  // 테스트 케이스
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
		}
		cout << n - 1 << '\n';  // 어차피 트리 구조면 전체 선회 가능한데요~? (모두가 연결그래프인거 보장) 
	}
}