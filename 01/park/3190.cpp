#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

int n, k, d = 0, l, length = 1;
int vec_idx = 0;
int sec = 0;

int arr[101][101] = { 0 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

pair<int, char> pair_vec[100] = { pair<int, char>(0, 'D') };
deque<pair<int, int> > deq;

bool check = false;

void move() {
	if (sec++ == pair_vec[vec_idx].first) {
		if (pair_vec[vec_idx++].second == 'D')
			d = (d + 1) % 4;
		else
			d = (d + 3) % 4;
	}
	int x = deq.front().first;
	int y = deq.front().second;

	int nx = x + dx[d];
	int ny = y + dy[d];

	if ((1 > nx || nx > n) || (1 > ny || ny > n)) {  // 맵 이탈
		check = true;
		return;
	}
	else if (arr[nx][ny] == -1) {  // 지 몸에 부딫힘
		check = true;
		return;
	}
	else if (arr[nx][ny] == 1) {  // 사과
		deq.push_front(pair<int, int>(nx, ny));
		arr[nx][ny] = -1;
	}
	else {  // 그냥 길
		deq.push_front(pair<int, int>(nx, ny));
		arr[nx][ny] = -1;
		arr[deq.back().first][deq.back().second] = 0;
		deq.pop_back();
	}
}

int main() {
	deq.push_back(pair<int, int>(1, 1));
	arr[1][1] = -1;

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		cin >> pair_vec[i].first >> pair_vec[i].second;
	}

	while (!check) {
		move();
	}

	cout << sec << endl;

	return 0;
}