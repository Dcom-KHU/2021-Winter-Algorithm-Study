#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; //연산의 개수
	cin >> n;
	priority_queue<int, vector<int>, less<int>> maxHeap;
	
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (!maxHeap.empty())
			{
				cout << maxHeap.top() << '\n';
				maxHeap.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			maxHeap.push(x);
	}
	return 0;
}