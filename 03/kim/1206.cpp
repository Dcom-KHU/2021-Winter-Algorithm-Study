#include <iostream>
#include <queue>
using namespace std;

#define SIZE 1000+1
int graph[SIZE][SIZE] = { 0, };
bool visited[SIZE] = { false, }; 
int n, m, v;//초기화

void reset() {
	for (int i = 0; i <= 1000; i++) visited[i] = false;
}// BFS출력후 그래프를 reset

void DFS(int v) { // DFS v는 시작점
	cout << v << " ";
	visited[v] = true; // v는 시작점이므로 true

	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && !visited[i]) { // 방문여부와 값이 있는지를 체크해서 둘다 만족시 실행
			visited[i] = true;
			DFS(i); // 최대한 깊숙히 들어가므로 재귀함수를 이용
		}
	}
	return;
}

void BFS(int v) {
	queue<int> que;
	que.push(v); // 시작점을 큐에 삽입

	visited[v] = true;

	while (!que.empty()) {
		int vertex = que.front();
		cout << vertex << " ";
		que.pop(); 

		visited[vertex] = true;

		for (int i = 1; i <= n; i++) {
			if (graph[vertex][i] && !visited[i]) {
				visited[i] = true;
				que.push(i); // 한지점에서 이동할수 있는만큼 최대한 큐에 삽입 BFS
			}
		}

	}

}

int main() {
	
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> v; // vertex, node, 시작점을 입력

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1; //그래프 초기화
	}

	DFS(v);
	cout << "\n"; //DFS로 출력

	reset(); // reset

	BFS(v);
	cout << "\n"; //BFS로 출력

	return 0;
}


