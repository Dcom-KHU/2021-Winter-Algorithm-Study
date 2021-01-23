#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXNODE 500+1
int n, m; //n:������ ����, m: ������ ����
vector<int> adjList[MAXNODE];
bool check[MAXNODE] = { false, };

bool isTree(int x, int prevNode) //bfs�̿��Ͽ� tree �����ľ� (cycle ������ ��� Ʈ�� x)
{
	check[x] = true;
	for (int i = 0; i < adjList[x].size(); i++)
	{
		if (adjList[x][i] != prevNode) //���� ��尡 ���� ��尡 �ƴ� ���(������ �׷����̹Ƿ� ��ġ�� ���� ����)
		{
			//���� ��带 �̹� �湮�� ���(����Ŭ ����) or �� ���� ��忡�� ����Ŭ�� ������ ���
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

//�׽�Ʈ���̽����� check �� ��������Ʈ �ʱ�ȭ
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
		if ((n == 0) && (m == 0)) //n=m=0�� ��� Ż��
			break; //���α׷� ����
		initCase();
		for (int i = 0; i < m; i++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			adjList[v1].push_back(v2);
			adjList[v2].push_back(v1);
		}
		//�� ������ ���ؼ� ����Ŭ ���翩�� Ȯ��
		int treeCnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!check[i]) //���� �˻����� ���� ��忡 ����(Ʈ���� ���� ����� �̹� check �Ǿ� ����)
			{
				if (isTree(i, i)) //�ش� ��尡 Ʈ�����
					treeCnt++;
			}
		}
		printTree(caseNum, treeCnt);
	}
	return 0;
}