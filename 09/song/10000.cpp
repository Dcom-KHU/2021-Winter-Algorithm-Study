#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) //x-r은 오름차순, x+r은 내림차순으로 정렬 (큰 원이 먼저 등장)
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

	int n; //원의 개수
	cin >> n;

	vector<pair<int, int>> circle;
	int x, r; //x:원의 중심 좌표, r: 반지름
	for (int i = 0;i < n;i++)
	{
		cin >> x >> r;
		circle.push_back({ x - r,x + r });
	}
	sort(circle.begin(), circle.end(), compare);

	stack<pair<int, int>> circleStack; //포함 관계에 있는 원들을 저장하는 stack
	//현재 포함관계에 있는 원(CircleStack내의 원) 중 가장 큰 원의 양 끝 좌표
	int maxLeft = circle[0].first;
	int maxRight = circle[0].second;
	circleStack.push(circle[0]);
	//이전에 참조한 원의 양 끝 좌표
	int prevLeft = maxLeft;
	int prevRight = maxRight;

	//같은 깊이에 속하며 서로 접하는 원들의 지름의 합 (stack에 깊이별로 저장)
	stack<int> depthDiameter; 
	depthDiameter.push(maxRight - maxLeft);

	int ret = 2; //결과값 (초깃값:n=1일 때)

	for (int i = 1; i < n; i++)
	{
		int thisDiameter = circle[i].second - circle[i].first; //현재의 원의 지름
		if (circle[i].first >= maxRight) //기존의 원에 포함되지 않는 새로운 원이 만들어진 경우
		{
			depthDiameter.push(thisDiameter);
			while (!circleStack.empty()) //스택 초기화
				circleStack.pop();
			circleStack.push(circle[i]);
			ret++;
			maxLeft = circle[i].first;
			maxRight = circle[i].second;
		}
		else //기존의 원에 포함되는 경우
		{
			//stack에 저장된 원들이 현재 원의 상위 관계가 아닐경우 pop (이 결과 상위 깊이의 원까지만 stack에 남게 됨)
			int currDepthDiameter = thisDiameter; //현재까지 저장된 같은 깊이의 지름의 합 저장용
			int currPrevRight = circleStack.top().second; //자신과 같은 깊이의 원의 오른쪽 좌표
			while (circleStack.top().second <= circle[i].first)
			{
				currPrevRight = circleStack.top().second;
				circleStack.pop();
				currDepthDiameter = depthDiameter.top();
				depthDiameter.pop();
			}
			if (circle[i].first == currPrevRight) //자신의 왼쪽의 원과 외접할 경우
			{
				int upperDiameter = circleStack.top().second - circleStack.top().first; //상위의 원의 지름
				if (currDepthDiameter + thisDiameter == upperDiameter) //상위의 원이 여러개의 원으로 나눠질 경우
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