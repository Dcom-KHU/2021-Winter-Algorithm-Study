#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int v;  // 정점 갯수
int first_max_d = 0;  // 최대 거리
int second_max_d = 0;
int root_node = 0;
bool first_check[100001] = { false };
bool second_check[100001] = { false };
vector<pair<int, int> > tree[100001];  // index, distance

void first_dfs(int x, int d) {  // 아무 노드에서 제일 멀리있는 노드를 찾는 과정
	first_check[x] = true;
	if (first_max_d < d) {
		root_node = x;
		first_max_d = d;
	}

	int length = tree[x].size();

	for (int i = 0; i < length; i++)
	{
		pair<int, int> p = tree[x][i];
		if (first_check[p.first] == false)
			first_dfs(p.first, d + p.second);
	}
}

void second_dfs(int x, int d) {  // 제일 멀리있는 노드, 루트 노드로 설정 후 지름 탐색
	second_check[x] = true;
	if (second_max_d < d) {
		root_node = x;
		second_max_d = d;
	}

	int length = tree[x].size();

	for (int i = 0; i < length; i++)
	{
		pair<int, int> p = tree[x][i];
		if (second_check[p.first] == false)
			second_dfs(p.first, d + p.second);
	}
}

int main() {
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		int n;
		cin >> n;

		int a, b;
		while (true)
		{
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			tree[n].push_back(make_pair(a, b));
		}
	}

	first_dfs(1, 0);  // 제일 멀리있는 노드를 루트노드로 설정
	second_dfs(root_node, 0);  // 거기서 제일 멀리있는게 진짜 멀리있는 노드
	cout << second_max_d << endl;
}