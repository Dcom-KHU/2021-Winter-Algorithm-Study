#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) //x-r�� ��������, x+r�� ������������ ���� (ū ���� ���� ����)
{
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //���� ����
	cin >> n;

	vector<pair<int, int>> circle;
	int x, r; //x:���� �߽� ��ǥ, r: ������
	for (int i = 0;i < n;i++)
	{
		cin >> x >> r;
		circle.push_back({ x - r,x + r });
	}
	sort(circle.begin(), circle.end(), compare);

	stack<pair<int, int>> circleStack; //���� ���迡 �ִ� ������ �����ϴ� stack
	//���� ���԰��迡 �ִ� ��(CircleStack���� ��) �� ���� ū ���� �� �� ��ǥ
	int maxLeft = circle[0].first;
	int maxRight = circle[0].second;
	circleStack.push(circle[0]);
	//������ ������ ���� �� �� ��ǥ
	int prevLeft = maxLeft;
	int prevRight = maxRight;

	//���� ���̿� ���ϸ� ���� ���ϴ� ������ ������ �� (stack�� ���̺��� ����)
	stack<int> depthDiameter; 
	depthDiameter.push(maxRight - maxLeft);

	int ret = 2; //����� (�ʱ갪:n=1�� ��)

	for (int i = 1; i < n; i++)
	{
		int thisDiameter = circle[i].second - circle[i].first; //������ ���� ����
		if (circle[i].first >= maxRight) //������ ���� ���Ե��� �ʴ� ���ο� ���� ������� ���
		{
			depthDiameter.push(thisDiameter);
			while (!circleStack.empty()) //���� �ʱ�ȭ
				circleStack.pop();
			circleStack.push(circle[i]);
			ret++;
			maxLeft = circle[i].first;
			maxRight = circle[i].second;
		}
		else //������ ���� ���ԵǴ� ���
		{
			//stack�� ����� ������ ���� ���� ���� ���谡 �ƴҰ�� pop (�� ��� ���� ������ �������� stack�� ���� ��)
			int currDepthDiameter = thisDiameter; //������� ����� ���� ������ ������ �� �����
			int currPrevRight = circleStack.top().second; //�ڽŰ� ���� ������ ���� ������ ��ǥ
			while (circleStack.top().second <= circle[i].first)
			{
				currPrevRight = circleStack.top().second;
				circleStack.pop();
				currDepthDiameter = depthDiameter.top();
				depthDiameter.pop();
			}
			if (circle[i].first == currPrevRight) //�ڽ��� ������ ���� ������ ���
			{
				int upperDiameter = circleStack.top().second - circleStack.top().first; //������ ���� ����
				if (currDepthDiameter + thisDiameter == upperDiameter) //������ ���� �������� ������ ������ ���
					ret++;
				currDepthDiameter += thisDiameter;
			}
			circleStack.push(circle[i]);
			depthDiameter.push(currDepthDiameter);
			ret++;
			prevLeft = circle[i].first;
			prevRight = circle[i].second;
		}
	}

	cout << ret;

	return 0;
}