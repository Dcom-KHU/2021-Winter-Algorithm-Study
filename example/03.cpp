#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Adjacent Matrix
bool a[6][6] = {
	{0, 1, 1, 0, 0, 0},
	{1, 0, 1, 1, 0, 0},
	{1, 1, 0, 1, 1, 0},
	{0, 1, 1, 0, 1, 1},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 0, 0}
};
bool check_dfs[6] = { false };
bool check_bfs[6] = { false };

void dfs(int x) {
	check_dfs[x] = true;
	for (int i = 0; i < 6; i++)
	{
		if (a[x][i] == true && check_dfs[i] == false)
		{
			dfs(i);
		}
	}
}

void bfs(int x) {
	check_bfs[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			if (a[y][i] == true && check_bfs[i] == false) {
				check_bfs[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	dfs(0);
	if (check_dfs[5])
		cout << "We Can Go 5!" << endl;
	else
		cout << "We Can't Go 5.." << endl;

	bfs(0);
	if (check_bfs[5])
		cout << "We Can Go 5!" << endl;
	else
		cout << "We Can't Go 5.." << endl;

	return 0;
}