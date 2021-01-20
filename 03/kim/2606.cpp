#include <iostream>
#include <queue>
using namespace std;

#define SIZE 1000+1
int network[SIZE][SIZE] = { 0, }; // ��ǻ�� ��Ʈ��ũ �׷���
bool visited[SIZE] = { false, }; // ���� ����
int netcom, infcom = 0; //��ǻ�� ������ ������ ��ǻ���� ��


void DFS(int v) { // DFS v�� ������
	infcom++; // ������ ��ǻ�� ����
	
	visited[v] = true; // ������

	for (int i = 1; i <= netcom; i++) {
		if (network[v][i] && !visited[i]) { // �湮���ο� ���� �ִ����� üũ�ؼ� �Ѵ� ������ ����
			visited[i] = true;
			DFS(i); // �ִ��� ����� ���Ƿ� ����Լ��� �̿�
		}
	}
	return;
}



int main() {

	ios::sync_with_stdio(false);

	int netnum; // ��Ʈ��ũ �����
	int x, y; // ����� ��ǥ
	cin >> netcom >> netnum; // ��ǻ�ͼ��� ����ȼ� �Է�
	for (int i = 0; i < netnum; i++) {
		
		cin >> x >> y;
		network[x][y] = 1;
		network[y][x] = 1; //�׷��� �ʱ�ȭ
	}

	DFS(1); // 1������ �����ϹǷ�
	cout << infcom -1 <<"\n"; // 1����ǻ�͸� ���� ������ ��ǻ���� �����̹Ƿ� 1����ǻ�ʹ� ����

	

	return 0;
}


