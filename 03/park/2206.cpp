#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

int n;  // 사람의 수
int a, b;  // 찾고자 하는 넘들
int m;  // 간선 수
bool arr[1001][1001];
int d[1001][1001][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(int x, int y, int z) {
	queue<pair<tuple<int, int, int>, int> > q;  // (인덱스, 거리)
	q.push(make_pair(make_tuple(x, y, z), 1));  // 시작점 삽입
	d[x][y][z] = 1;

	while (!q.empty()) {
		pair<tuple<int, int, int>, int> p = q.front();
		q.pop();
		int x = get<0>(p.first);  // x
		int y = get<1>(p.first);  // y
		int z = get<2>(p.first);  // 통과 했는지 안 했는지
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;

			if ((nx >= 1 && nx <= n) && (ny >= 1 && ny <= m)) {  // 범위 안
				if (arr[nx][ny] == 0) {  // 벽이 뚫려있을때
					if (d[nx][ny][nz] == -1 || d[nx][ny][nz] > p.second + 1) {  // 거리가 설정이 되지 않았거나, 거리가 더 짧을 때 갱신
						d[nx][ny][nz] = p.second + 1;
						q.push(make_pair(make_tuple(nx, ny, nz), p.second + 1));  // Push
					}
				} else {  // 벽이 막혀있을때
					if (nz == 0) {  // 아직 벽 부순적 없을때
						nz += 1;
						if (d[nx][ny][nz] == -1 || d[nx][ny][nz] > p.second + 1) {  // 거리가 설정이 되지 않았거나, 거리가 더 짧을 때 갱신
							d[nx][ny][nz] = p.second + 1;
							q.push(make_pair(make_tuple(nx, ny, nz), p.second + 1));  // Push
						}
					}
				}
			}
		}	
	}
}

int main() {
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			d[i][j][0] = d[i][j][1] = -1;
		}
	}
	cin >> n >> m;

	cin.clear();
	cin.ignore();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = cin.get() - '0';
		}
		cin.get();
	}

	bfs(1, 1, 0);

	if (d[n][m][0] == -1 && d[n][m][1] == -1) {
		cout << -1 << endl;
	}
	else if (d[n][m][0] == -1) {
		cout << d[n][m][1] << endl;
	}
	else if (d[n][m][1] == -1) {
		cout << d[n][m][0] << endl;
	}
	else {
		cout << min(d[n][m][0], d[n][m][1]) << endl;
	}
}