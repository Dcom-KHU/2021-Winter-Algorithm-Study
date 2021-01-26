#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 100000 + 1
vector<int> v[SIZE]; //트리를 저장하는 벡터
int p[SIZE]; // 부모를 저장하는 배열 ex) p[2] = 2의 부모노드 
bool visited[SIZE]; // 방문여부
int n; // 노드의 개수



void bfs(int a) {//bfs를 돌면서 부모배열에 노드를 순서대로 저장
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		visited[current] = true;
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i];
			if (!visited[next]) { // 자식노드가 있다.
				visited[next] = true; // 방문완료
				p[next] = current; // 현재노드가 다음노드의 부모가됨
				q.push(next);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) { // 트리 생성
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)//부모노드를 2번부터 출력해야 하므로 2부터 출력
		cout << p[i] << "\n";

	return 0;
}
