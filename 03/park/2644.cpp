#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n;  // 사람의 수
int a, b;  // 찾고자 하는 넘들
int m;  // 간선 수
bool arr[101][101] = { false };
bool check[101] = { false };

int bfs(int x) {
	queue<pair<int, int> > q;  // (인덱스, 거리)
	q.push(make_pair(x, 0));  // 시작점 삽입
	check[x] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		
		if (p.first == b)
			return p.second;  // b에 도착 시
		
		for (int i = 1; i <= n; i++)
		{
			if (arr[p.first][i] == true && check[i] == false) {
				check[i] = true;
				q.push(make_pair(i, p.second + 1));
			}
		}
	}
	return -1;  // 못 찾았으면 여기로 오겠쥬?
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = true;
	}

	cout << bfs(a) << endl;
}