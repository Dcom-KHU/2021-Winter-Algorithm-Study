#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;  // 원소 갯수
int arr[1001];  // 원소 저장
int dp[1001] = { 0 };  // 길이 저장
int mem[1001] = { 0 };  // 전 원소의 위치 저장
int max_index = 0;  // 길이가 최고로 긴 배열의 끝 index 갱신

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int long_index = 0;  // 자기보다 작은 원소중에 길이가 최고로 긴 배열 찾기
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j]) {
				if (dp[long_index] < dp[j]) {
					long_index = j;
				}
			}
		}
		dp[i] = dp[long_index] + 1;
		mem[i] = long_index;  // 전 인덱스 저장

		if (dp[i] > dp[max_index]) {
			max_index = i;  // 현재 원소의 dp가 max_index보다 크면 갱심
		}
	}

	cout << dp[max_index] << endl;  // 최고 길이
	
	int temp = max_index;
	stack<int> s;
	
	while (temp != 0) {  // 반복문을 통해 저장 된 원소를 찾아감
		s.push(temp);
		temp = mem[temp];
	}

	while (!s.empty()) {  // 스택을 통해 원래의 순서대로 반환
		cout << arr[s.top()] << ' ';
		s.pop();
	}
	cout << endl;

	return 0;
}