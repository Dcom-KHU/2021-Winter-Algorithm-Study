#include <iostream>
#include <queue>
using namespace std;

//코드 간략화 위해 전역변수 사용 (재귀함수 인자 등)
int n, m, v; //n:정점의 개수, m:간선의 개수, v:탐색 시작정점의 번호
bool check[1001] = { false, }; //1<=m<=1000, 1000번째 인덱스 사용하기 위해 1001개 크기 배열 사용
bool adjacentMatrix[1001][1001] = { false, };
queue<int> q; //bfs에 사용

void dfs(int x)
{
	cout << x << " ";
	check[x] = true;
	for (int i = 1; i <= n; i++)
	{
		if (adjacentMatrix[x][i] && !check[i])
			dfs(i);
	}
}

void bfs(int x)
{
	check[x] = true;
	q.push(x);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";
		for (int i = 1; i <= n; i++)
		{
			if (adjacentMatrix[tmp][i] && !check[i])
			{
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> v;
	
	//인접행렬 초기화
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		
		//양방향그래프이므로 같은 경로끼리 초기화
		adjacentMatrix[n1][n2] = true;
		adjacentMatrix[n2][n1] = true;
	}

	dfs(v);
	cout << endl;

	//bfs 사용하기 위해 check 초기화
	for (int i = 1; i <= n; i++)
		check[i] = false;
	bfs(v);

	return 0;
}