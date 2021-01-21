#include <iostream>
#include <vector>
#include <memory.h> //memset() 사용 시 vs에서는 없어도 작동되나, 백준에서는 이 헤더가 있어야 사용가능
using namespace std;

#define RED 1
#define BLUE 2

int v, e; //v:정점의 개수, e:간선의 개수
int color[20001] = { 0, }; //방문하지 않았을 경우 0, 색깔은 red&blue로 표시
vector<int> adjacentList[20001];

//테스트케이스마다 color 및 인접행렬 초기화
void clearList()
{
	memset(color, 0, sizeof(color));
	for (int i = 0; i < 20001; i++)
		adjacentList[i].clear();
}

//dfs 진행하며 check한 정점에 색깔 기록
void setColor(int x, int _color)
{
	color[x] = _color;
	for (int i = 0; i < adjacentList[x].size(); i++)
	{
		if (color[adjacentList[x][i]] == 0)
			setColor(adjacentList[x][i], 3 - _color); //반대 색깔 인자로 주어 함수 실행
	}
}

//이분그래프 여부 확인
bool isBipartite()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < adjacentList[i].size(); j++)
		{
			if (color[i] == color[adjacentList[i][j]]) //서로 색깔이 같으면
				return false; //이분그래프가 아님
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k; //테스트 케이스의 개수
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		//인접리스트 초기화
		clearList();
		for (int j = 0; j < e; j++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			adjacentList[v1].push_back(v2);
			adjacentList[v2].push_back(v1);
		}

		for (int i = 1; i <= v; i++) //분리되어있는 정점이 있을 수 있으므로 반복문 통해 color 설정
		{
			if (color[i] == 0)
				setColor(i, RED);
		}
		if (isBipartite())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}