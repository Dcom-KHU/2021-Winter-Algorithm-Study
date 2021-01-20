#include <iostream>
#include <queue>
using namespace std;

//�ڵ� ����ȭ ���� �������� ��� (����Լ� ���� ��)
int n, m, v; //n:������ ����, m:������ ����, v:Ž�� ���������� ��ȣ
bool check[1001] = { false, }; //1<=m<=1000, 1000��° �ε��� ����ϱ� ���� 1001�� ũ�� �迭 ���
bool adjacentMatrix[1001][1001] = { false, };
queue<int> q; //bfs�� ���

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
	
	//������� �ʱ�ȭ
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		
		//�����׷����̹Ƿ� ���� ��γ��� �ʱ�ȭ
		adjacentMatrix[n1][n2] = true;
		adjacentMatrix[n2][n1] = true;
	}

	dfs(v);
	cout << endl;

	//bfs ����ϱ� ���� check �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		check[i] = false;
	bfs(v);

	return 0;
}