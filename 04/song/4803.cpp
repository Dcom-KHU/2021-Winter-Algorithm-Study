#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXNODE 500+1
int n, m; //n:정점의 개수, m: 간선의 개수
vector<int> adjList[MAXNODE];
bool check[MAXNODE] = { false, };

bool isTree(int x, int prevNode) //bfs이용하여 tree 개수파악 (cycle 형성될 경우 트리 x)
{
	check[x] = true;
	for (int i = 0; i < adjList[x].size(); i++)
	{
		if (adjList[x][i] != prevNode) //다음 노드가 직전 노드가 아닌 경우(무방향 그래프이므로 겹치는 간선 무시)
		{
			//다음 노드를 이미 방문한 경우(사이클 형성) or 그 하위 노드에서 사이클이 형성될 경우
			if ((check[adjList[x][i]]) || (!isTree(adjList[x][i], x)))
				return false;
		}
	}
	return true;
}

void printTree(int caseNum, int treeCnt)
{
	cout << "Case " << caseNum << ": ";
	switch (treeCnt)
	{
	case 0:
		cout << "No trees.\n";
		break;
	case 1:
		cout << "There is one tree.\n";
		break;
	default:
		cout << "A forest of " << treeCnt << " trees.\n";
		break;
	}
}

//테스트케이스마다 check 및 인접리스트 초기화
void initCase()
{
	memset(check, false, sizeof(check));
	for (int i = 0; i < MAXNODE; i++)
		adjList[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int caseNum = 0;
	while (true)
	{
		caseNum++;
		cin >> n >> m;
		if ((n == 0) && (m == 0)) //n=m=0일 경우 탈출
			break; //프로그램 종료
		initCase();
		for (int i = 0; i < m; i++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			adjList[v1].push_back(v2);
			adjList[v2].push_back(v1);
		}
		//각 정점에 대해서 사이클 존재여부 확인
		int treeCnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!check[i]) //아직 검사하지 않은 노드에 대해(트리에 속한 노드라면 이미 check 되어 있음)
			{
				if (isTree(i, i)) //해당 노드가 트리라면
					treeCnt++;
			}
		}
		printTree(caseNum, treeCnt);
	}
	return 0;
}