#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> line;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //���� ���� Ƚ��
	cin >> n;

	int x, y;
	for (int i = 0;i < n;i++)
	{
		cin >> x >> y;
		line.push_back({ x, y });
	}
	sort(line.begin(), line.end());

	x = line[0].first;
	y = line[0].second;
	int ret = 0; //�����
	for (int i = 1;i < n;i++)
	{
		if ((x <= line[i].first) && (line[i].first <= y)) //���� ���� ���ļ� �׷��� ���
		{
			if(line[i].second > y)
				y = line[i].second;
		}
		else //��ġ�� �ʴ� ��� (���ο� ���� ��������� ���)
		{
			ret += y - x; //������ �׷��� ���� ���� ����
			x = line[i].first;
			y = line[i].second;
		}
	}
	ret += y - x; //������ �׷��� ���� ���� ����

	cout<<ret;

	return 0;
}