#include <iostream>
#include <vector>
#include <memory.h> //memset() ��� �� vs������ ��� �۵��ǳ�, ���ؿ����� �� ����� �־�� ��밡��
using namespace std;

#define RED 1
#define BLUE 2

int v, e; //v:������ ����, e:������ ����
int color[20001] = { 0, }; //�湮���� �ʾ��� ��� 0, ������ red&blue�� ǥ��
vector<int> adjacentList[20001];

//�׽�Ʈ���̽����� color �� ������� �ʱ�ȭ
void clearList()
{
	memset(color, 0, sizeof(color));
	for (int i = 0; i < 20001; i++)
		adjacentList[i].clear();
}

//dfs �����ϸ� check�� ������ ���� ���
void setColor(int x, int _color)
{
	color[x] = _color;
	for (int i = 0; i < adjacentList[x].size(); i++)
	{
		if (color[adjacentList[x][i]] == 0)
			setColor(adjacentList[x][i], 3 - _color); //�ݴ� ���� ���ڷ� �־� �Լ� ����
	}
}

//�̺б׷��� ���� Ȯ��
bool isBipartite()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < adjacentList[i].size(); j++)
		{
			if (color[i] == color[adjacentList[i][j]]) //���� ������ ������
				return false; //�̺б׷����� �ƴ�
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k; //�׽�Ʈ ���̽��� ����
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		//��������Ʈ �ʱ�ȭ
		clearList();
		for (int j = 0; j < e; j++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			adjacentList[v1].push_back(v2);
			adjacentList[v2].push_back(v1);
		}

		for (int i = 1; i <= v; i++) //�и��Ǿ��ִ� ������ ���� �� �����Ƿ� �ݺ��� ���� color ����
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