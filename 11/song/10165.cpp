#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n; //���� �������� ����
int m; //���� �뼱�� ��

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) //�뼱 ���� ���� �������� ����
{
	//from < to �� ���� from - to, from > to �� ���� n - (from - to)
	int aDistance, bDistance;
	aDistance = (get<1>(a) > get<0>(a)) ? (get<1>(a) - get<0>(a)) : (n + get<1>(a) - get<0>(a));
	bDistance = (get<1>(b) > get<0>(b)) ? (get<1>(b) - get<0>(b)) : (n + get<1>(b) - get<0>(b));
	return aDistance > bDistance;
}

bool compareNum(const tuple<int, int, int>& a, const tuple<int, int, int>& b) //�뼱 ��ȣ ���� �������� ����
{
	return get<2>(a) < get<2>(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<tuple<int, int, int>> route; //{�����, ������, �뼱��ȣ}

	int from, to;
	for (int i = 0;i < m;i++)
	{
		cin >> from >> to;
		route.push_back({ from,to,i + 1 });
	}
	sort(route.begin(), route.end(), compare);

	vector<tuple<int, int, int>> confirmed; //��� ����Ǵ� �� Ȯ���� �뼱

	//route�� �ִ� �뼱���� confirmed�� �ִ� �뼱��κ��� �ߺ� ���θ� �˻��Ѵ�.
	//�ߺ����� �ʴ� �뼱�� ��� confirmed�� push�Ѵ�.
	for (auto r : route)
	{
		bool isIncluded = false;
		int rFrom = get<0>(r);
		int rTo = get<1>(r);
		for (auto c : confirmed) //r�� c�� ���ԵǴ��� Ȯ���Ѵ�.
		{
			int cFrom = get<0>(c);
			int cTo = get<1>(c);
			if (cFrom > cTo) //c�� 0�� ������ �뼱�� ���
			{
				if (rFrom > rTo) //r�� 0�� ������ �뼱�� ���
				{
					if ((cFrom <= rFrom) && (rTo <= cTo))
					{
						isIncluded = true;
						break;
					}
				}
				else //r�� 0�� ������ �ʴ� �뼱�� ���
				{
					if ((cFrom <= rFrom) || (rTo <= cTo))
					{
						isIncluded = true;
						break;
					}
				}
			}
			else //c�� 0�� ������ �ʴ� �뼱�� ���
			{
				if ((cFrom <= rFrom) && (rFrom < cTo)) //rFrom�� c�� ���ԵǴ� ����
				{
					if ((rFrom < rTo) && (rTo <= cTo)) //rTo�� c�� ���ԵǴ� ����
					{
						isIncluded = true;
						break;
					}
				}
			}
		}
		if (!isIncluded)
			confirmed.push_back(r);
	}
	sort(confirmed.begin(), confirmed.end(), compareNum);

	for (auto c : confirmed)
		cout << get<2>(c) << " ";

	return 0;
}