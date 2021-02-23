#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n; //버스 정류소의 개수
int m; //버스 노선의 수

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) //노선 길이 기준 내림차순 정렬
{
	//from < to 일 때는 from - to, from > to 일 때는 n - (from - to)
	int aDistance, bDistance;
	aDistance = (get<1>(a) > get<0>(a)) ? (get<1>(a) - get<0>(a)) : (n + get<1>(a) - get<0>(a));
	bDistance = (get<1>(b) > get<0>(b)) ? (get<1>(b) - get<0>(b)) : (n + get<1>(b) - get<0>(b));
	return aDistance > bDistance;
}

bool compareNum(const tuple<int, int, int>& a, const tuple<int, int, int>& b) //노선 번호 기준 오름차순 정렬
{
	return get<2>(a) < get<2>(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<tuple<int, int, int>> route; //{출발지, 도착지, 노선번호}

	int from, to;
	for (int i = 0;i < m;i++)
	{
		cin >> from >> to;
		route.push_back({ from,to,i + 1 });
	}
	sort(route.begin(), route.end(), compare);

	vector<tuple<int, int, int>> confirmed; //계속 운행되는 게 확정된 노선

	//route에 있는 노선들을 confirmed에 있는 노선들로부터 중복 여부를 검사한다.
	//중복되지 않는 노선일 경우 confirmed에 push한다.
	for (auto r : route)
	{
		bool isIncluded = false;
		int rFrom = get<0>(r);
		int rTo = get<1>(r);
		for (auto c : confirmed) //r이 c에 포함되는지 확인한다.
		{
			int cFrom = get<0>(c);
			int cTo = get<1>(c);
			if (cFrom > cTo) //c가 0을 지나는 노선일 경우
			{
				if (rFrom > rTo) //r도 0을 지나는 노선일 경우
				{
					if ((cFrom <= rFrom) && (rTo <= cTo))
					{
						isIncluded = true;
						break;
					}
				}
				else //r이 0을 지나지 않는 노선일 경우
				{
					if ((cFrom <= rFrom) || (rTo <= cTo))
					{
						isIncluded = true;
						break;
					}
				}
			}
			else //c가 0을 지나지 않는 노선일 경우
			{
				if ((cFrom <= rFrom) && (rFrom < cTo)) //rFrom이 c에 포함되는 조건
				{
					if ((rFrom < rTo) && (rTo <= cTo)) //rTo가 c에 포함되는 조건
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