#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;

	priority_queue<int, vector<int>, less<int> > left_queue;  // 왼쪽 큐, 오른 쪽 큐보다 항상 많아야 함
	priority_queue<int, vector<int>, greater<int> > right_queue;  // 오른쪽 큐

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (left_queue.size() == right_queue.size()) {
			if (left_queue.size() == 0 && right_queue.size() == 0) {  // 0 인경우
				left_queue.push(temp);
			}
			else {
				if (right_queue.top() < temp) {  // 값이 오른쪽 큐에 넣어야 할 값이면
					int t = right_queue.top();
					right_queue.pop();
					right_queue.push(temp);
					left_queue.push(t);  // 오른쪽 큐에서 가장 작은 값을 빼서 왼쪽 큐에 넣음
				}
				else {
					left_queue.push(temp);  // 아니면 왼쪽 큐에 넣고
				}
			}
		}
		else if (left_queue.size() > right_queue.size()) {  // 왼쪽 큐에 든게 더 많을때
			if (left_queue.top() > temp) {  // 왼쪽 큐에 넣어야 할것
				int t = left_queue.top();
				left_queue.pop();
				left_queue.push(temp);
				right_queue.push(t);  // 왼쪽 큐에서 가장 큰 값을 빼서 오른 쪽 큐에 삽입
			}
			else {
				right_queue.push(temp);  // 아니면 오른쪽 큐에 넣고
			}
		}
		cout << left_queue.top() << '\n';  // 왼쪽 큐에서 가장 큰 값이 중앙값
	}
}