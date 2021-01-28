/* ���ذ� - �Ʒ� �ݷʸ� ���� �ذ����� ����
5 5
#####
#SXXE
#XX.#
#...#
#####
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
using namespace std;

#define MAXSIZE 50

char house[MAXSIZE][MAXSIZE];
int n, m; //n:���� ����, m:���� ����
int xCount = 0; //ã�ƾ� �ϴ� ���� X�� ����
int sLoc[2]; //S�� ��ǥ
int eLoc[2]; //E�� ��ǥ

bool checkAvailableRange(int x, int y)
{
	if (house[x][y] == '#')
		return false;
	else
		return true;
}

//bfs
int dist[MAXSIZE][MAXSIZE][1 << 5]; //dist�� 3��° ������ X�� ���濩�θ� ��Ʈ�� ǥ�� (�ʱ갪 -1)
queue<tuple<int, int, int>> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 }; //������� �� �� �� �� (�ð����)
int bfs(int _x, int _y, int _bitX)
{
	while (!q.empty())
		q.pop();
	dist[_x][_y][_bitX] = 0; //�湮�� ĭ�� ���� 0�� ǥ��
	q.push(make_tuple(_x, _y, _bitX));
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int bitX = get<2>(q.front()); //X�� ���濩�θ� ��Ʈ�� ǥ�� (ex. �� 5���� X�� 1,3�� X�� �������� ��� 00101)
		q.pop();

		int curr = house[x][y]; //���� ��ġ
		if ((curr > 0) && (curr <= 5) && ((bitX & (1 << curr-1)) == 0)) //�� ��ġ���� ���� �������� ���� X�� �߰����� ��� (0<=X<=5)
		{
			int accumulatedDist = dist[x][y][bitX]; //���������κ��� �� ��ġ���� ������ �Ÿ�
			bitX = bitX | (1 << curr - 1); //�ش� X�� �� ��Ʈ����ŷ
			return accumulatedDist + bfs(x, y, bitX);
		}
		else if ((x == eLoc[0]) && (y == eLoc[1]) && (bitX == (1 << xCount) - 1)) //E�� ���������� ��� X�� ����� ���
			return dist[x][y][bitX];

		for (int i = 0; i < 4; i++)
		{
			//�̵��������� Ȯ�� �� ������ǥ
			int checkX = x + dx[i];
			int checkY = y + dy[i];
			if (checkAvailableRange(checkX, checkY) && dist[checkX][checkY][bitX] == -1) //�̵������ϸ� ���� Ȯ������ ���� ĭ�� ����
			{
				q.push(make_tuple(checkX, checkY, bitX));
				dist[checkX][checkY][bitX] = dist[x][y][bitX] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	//���� ���� �Է�
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			char block;
			cin >> block;
			if (block == 'X') //block�� X�� ��� X�� �ѹ����Ͽ� �迭�� �Է�
				house[row][col] = ++xCount;
			else
				house[row][col] = block;
			if (block == 'S')
			{
				sLoc[0] = row;
				sLoc[1] = col;
			}
			else if (block == 'E')
			{
				eLoc[0] = row;
				eLoc[1] = col;
			}
		}
	}

	//bfs �̿��Ͽ� �ִܰŸ� ���
	memset(dist, -1, sizeof(dist));
	int minRoute = bfs(sLoc[0], sLoc[1], 0);
	cout << minRoute;

	return 0;
}
