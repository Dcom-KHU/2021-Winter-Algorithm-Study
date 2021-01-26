#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 100000 + 1
vector<int> v[SIZE]; //Ʈ���� �����ϴ� ����
int p[SIZE]; // �θ� �����ϴ� �迭 ex) p[2] = 2�� �θ��� 
bool visited[SIZE]; // �湮����
int n; // ����� ����



void bfs(int a) {//bfs�� ���鼭 �θ�迭�� ��带 ������� ����
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		visited[current] = true;
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i];
			if (!visited[next]) { // �ڽĳ�尡 �ִ�.
				visited[next] = true; // �湮�Ϸ�
				p[next] = current; // �����尡 ��������� �θ𰡵�
				q.push(next);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) { // Ʈ�� ����
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)//�θ��带 2������ ����ؾ� �ϹǷ� 2���� ���
		cout << p[i] << "\n";

	return 0;
}
