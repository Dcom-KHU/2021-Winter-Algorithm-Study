#include <iostream>
#include <queue>
using namespace std;

#define SIZE 1000+1
int graph[SIZE][SIZE] = { 0, };
bool visited[SIZE] = { false, }; 
int n, m, v;//�ʱ�ȭ

void reset() {
	for (int i = 0; i <= 1000; i++) visited[i] = false;
}// BFS����� �׷����� reset

void DFS(int v) { // DFS v�� ������
	cout << v << " ";
	visited[v] = true; // v�� �������̹Ƿ� true

	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && !visited[i]) { // �湮���ο� ���� �ִ����� üũ�ؼ� �Ѵ� ������ ����
			visited[i] = true;
			DFS(i); // �ִ��� ����� ���Ƿ� ����Լ��� �̿�
		}
	}
	return;
}

void BFS(int v) {
	queue<int> que;
	que.push(v); // �������� ť�� ����

	visited[v] = true;

	while (!que.empty()) {
		int vertex = que.front();
		cout << vertex << " ";
		que.pop(); 

		visited[vertex] = true;

		for (int i = 1; i <= n; i++) {
			if (graph[vertex][i] && !visited[i]) {
				visited[i] = true;
				que.push(i); // ���������� �̵��Ҽ� �ִ¸�ŭ �ִ��� ť�� ���� BFS
			}
		}

	}

}

int main() {
	
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> v; // vertex, node, �������� �Է�

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1; //�׷��� �ʱ�ȭ
	}

	DFS(v);
	cout << "\n"; //DFS�� ���

	reset(); // reset

	BFS(v);
	cout << "\n"; //BFS�� ���

	return 0;
}


