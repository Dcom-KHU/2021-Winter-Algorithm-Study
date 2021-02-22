#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXSIZE 200000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //������ ����
	priority_queue<int, vector<int>, greater<int>> classroom; //�̿� ������ �ּ� �ð��� ��� �ִ� min heap
	int ret = 0; //�����

	cin >> n;
	pair<int, int> lecture[MAXSIZE];
	for (int i = 0; i < n; i++)
		cin >> lecture[i].first >> lecture[i].second;
	sort(lecture, lecture + n);
	classroom.push(lecture[0].second);
	
	for (int i = 1; i < n; i++)
	{
		if (classroom.top() <= lecture[i].first)
			classroom.pop();
		classroom.push(lecture[i].second);
	}
	
	cout << classroom.size();

	return 0;
}