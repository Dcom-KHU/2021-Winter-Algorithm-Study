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

bool checkAvailableRange(int x, int y)
{
	if (house[x][y] == '#')
		return false;
	else
		return true;
}

//bfs
int dist[MAXSIZE][MAXSIZE][1 << 5] = { 0, }; //dist�� 3��° ������ X�� ���濩�θ� ��Ʈ�� ǥ�� (�ʱ갪 -1)
queue<tuple<int, int, int>> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 }; //������� �� �� �� �� (�ð����)
void bfs(int _x, int _y, int _bitX)
{
	dist[_x][_y][_bitX] = 0;
	q.push(make_tuple(_x, _y, _bitX));

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int bitX = get<2>(q.front()); //X�� ���濩�θ� ��Ʈ�� ǥ�� (ex. �� 5���� X�� 1,3�� X�� �������� ��� 00101)
		q.pop();
		
		//E�� ���������� ��� X�� ����� ���
		if ((house[x][y] == 'E') && (bitX == (1 << xCount) - 1)) 
		{
			cout << dist[x][y][bitX];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			//�̵��������� Ȯ�� �� ������ǥ
			int checkX = x + dx[i];
			int checkY = y + dy[i];
			int checkBitX = bitX;
			if (checkAvailableRange(checkX, checkY) && dist[checkX][checkY][bitX] == -1) //�̵������ϸ� ���� Ȯ������ ���� ĭ�� ����
			{
				int next = house[checkX][checkY];
				if ((next > 0) && (next <= 5) && ((checkBitX & (1 << next - 1)) == 0)) //���� ��ġ���� ���� �������� ���� X�� �߰����� ��� (0<=X<=5)
					checkBitX = bitX | (1 << next - 1); //�ش� X�� �� ��Ʈ����ŷ
				q.push(make_tuple(checkX, checkY, checkBitX));
				dist[checkX][checkY][checkBitX] = dist[x][y][bitX] + 1;
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
		}
	}

	//bfs �̿��Ͽ� �ִܰŸ� ���
	memset(dist, -1, sizeof(dist));
	bfs(sLoc[0], sLoc[1], 0);

	return 0;
}
