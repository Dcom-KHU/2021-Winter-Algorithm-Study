//�� �ڵ�� �˰��� �����δ� ������ ���ؿ��� �������� �޸� �ʰ��� ���а� ��ϴ�..
//���� ����Ʈ�� �ٲٸ� �ذ�ȴٰ�� �ϴµ� �ð� ������ �� �ذ��߽��ϴ� ��
//���� �ð��ȿ� �����ؼ� �ø��ڽ��ϴ� ����

#include <iostream>
using namespace std;

#define RED 1
#define BLUE 2

int v, e; //v:������ ����, e:������ ����
int check[20001] = { 0, }; //�湮���� �ʾ��� ��� 0, ������ red&blue�� ǥ��
bool adjacentMatrix[20001][20001] = { false, };

//dfs �����ϸ� check�� ������ ���� ���
void setColor(int x, int color)
{
	check[x] = color;
	for (int i = 1; i <= v; i++)
	{
		if (adjacentMatrix[x][i] && check[i] == 0)
			setColor(i, 3 - color); //�ݴ� ���� ���ڷ� �־� �Լ� ����
	}
}

//�̺б׷��� ���� Ȯ��
bool isBipartite()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (adjacentMatrix[i][j] == true) //���� ������ ���ؼ�
			{
				if (check[i] == check[j]) //���� ������ ������
					return false; //�̺б׷����� �ƴ�
			}
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
		
		//������� �ʱ�ȭ
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