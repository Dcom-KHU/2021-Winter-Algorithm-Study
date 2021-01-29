#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
using namespace std;

#define MAXSIZE 50

char house[MAXSIZE][MAXSIZE];
int n, m; //n:가로 길이, m:세로 길이
int xCount = 0; //찾아야 하는 물건 X의 개수
int sLoc[2]; //S의 좌표

bool checkAvailableRange(int x, int y)
{
	if (house[x][y] == '#')
		return false;
	else
		return true;
}

//bfs
int dist[MAXSIZE][MAXSIZE][1 << 5] = { 0, }; //dist의 3번째 차원은 X의 습득여부를 비트로 표현 (초깃값 -1)
queue<tuple<int, int, int>> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 }; //순서대로 상 우 하 좌 (시계방향)
void bfs(int _x, int _y, int _bitX)
{
	dist[_x][_y][_bitX] = 0;
	q.push(make_tuple(_x, _y, _bitX));

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int bitX = get<2>(q.front()); //X의 습득여부를 비트로 표현 (ex. 총 5개의 X중 1,3번 X를 습득했을 경우 00101)
		q.pop();
		
		//E에 도착했으며 모든 X를 모았을 경우
		if ((house[x][y] == 'E') && (bitX == (1 << xCount) - 1)) 
		{
			cout << dist[x][y][bitX];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			//이동가능한지 확인 할 인접좌표
			int checkX = x + dx[i];
			int checkY = y + dy[i];
			int checkBitX = bitX;
			if (checkAvailableRange(checkX, checkY) && dist[checkX][checkY][bitX] == -1) //이동가능하며 아직 확인하지 않은 칸에 대해
			{
				int next = house[checkX][checkY];
				if ((next > 0) && (next <= 5) && ((checkBitX & (1 << next - 1)) == 0)) //다음 위치에서 아직 습득하지 않은 X를 발견했을 경우 (0<=X<=5)
					checkBitX = bitX | (1 << next - 1); //해당 X의 값 비트마스킹
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

	//집의 구조 입력
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			char block;
			cin >> block;
			if (block == 'X') //block이 X일 경우 X에 넘버링하여 배열에 입력
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

	//bfs 이용하여 최단거리 계산
	memset(dist, -1, sizeof(dist));
	bfs(sLoc[0], sLoc[1], 0);

	return 0;
}
