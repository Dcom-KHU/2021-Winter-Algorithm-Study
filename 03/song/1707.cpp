//이 코드는 알고리즘 상으로는 맞으나 백준에서 돌려보면 메모리 초과로 실패가 뜹니다..
//인접 리스트로 바꾸면 해결된다고는 하는데 시간 문제로 못 해결했습니다 ㅎ
//빠른 시간안에 수정해서 올리겠습니다 ㅎㅎ

#include <iostream>
using namespace std;

#define RED 1
#define BLUE 2

int v, e; //v:정점의 개수, e:간선의 개수
int check[20001] = { 0, }; //방문하지 않았을 경우 0, 색깔은 red&blue로 표시
bool adjacentMatrix[20001][20001] = { false, };

//dfs 진행하며 check한 정점에 색깔 기록
void setColor(int x, int color)
{
	check[x] = color;
	for (int i = 1; i <= v; i++)
	{
		if (adjacentMatrix[x][i] && check[i] == 0)
			setColor(i, 3 - color); //반대 색깔 인자로 주어 함수 실행
	}
}

//이분그래프 여부 확인
bool isBipartite()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (adjacentMatrix[i][j] == true) //인접 정점에 대해서
			{
				if (check[i] == check[j]) //서로 색깔이 같으면
					return false; //이분그래프가 아님
			}
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
		
		//인접행렬 초기화
		for (int j = 0; j < e; j++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			adjacentMatrix[v1][v2] = adjacentMatrix[v2][v1] = true;
		}

		setColor(1,RED);
		if (isBipartite())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}