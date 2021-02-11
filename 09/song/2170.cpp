#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> line;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //선을 그은 횟수
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
	int ret = 0; //결과값
	for (int i = 1;i < n;i++)
	{
		if ((x <= line[i].first) && (line[i].first <= y)) //이전 선에 겹쳐서 그려질 경우
		{
			if(line[i].second > y)
				y = line[i].second;
		}
		else //겹치지 않는 경우 (새로운 선이 만들어지는 경우)
		{
			ret += y - x; //이전에 그려진 선의 길이 저장
			x = line[i].first;
			y = line[i].second;
		}
	}
	ret += y - x; //이전에 그려진 선의 길이 저장

	cout<<ret;

	return 0;
}