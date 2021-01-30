#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;


int k, n;
int result = 0;
vector<long> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	// 1. 우선 순위 순으로 뽑아주는 컨테이너
	priority_queue<long, vector<long>, greater<long> > pq;

	for (int i : vec) {
		pq.push(i);
	}

	long head = 0;

	for (int i = 0; i < n; i++)
	{
		head = pq.top();
		pq.pop();

		for (int j = 0; j < k; j++)
		{
			long value = head * vec[j];
			pq.push(value);

			if (head % vec[j] == 0)
				break;
		}
	}
	cout << head << endl;

	return 0;
}