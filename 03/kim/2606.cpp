#include <iostream>
#include <queue>
using namespace std;

#define SIZE 1000+1
int network[SIZE][SIZE] = { 0, }; // 컴퓨터 네트워크 그래프
bool visited[SIZE] = { false, }; // 감염 여부
int netcom, infcom = 0; //컴퓨터 개수와 감염된 컴퓨터의 수


void DFS(int v) { // DFS v는 시작점
	infcom++; // 감염된 컴퓨터 증가
	
	visited[v] = true; // 감염됨

	for (int i = 1; i <= netcom; i++) {
		if (network[v][i] && !visited[i]) { // 방문여부와 값이 있는지를 체크해서 둘다 만족시 실행
			visited[i] = true;
			DFS(i); // 최대한 깊숙히 들어가므로 재귀함수를 이용
		}
	}
	return;
}



int main() {

	ios::sync_with_stdio(false);

	int netnum; // 네트워크 연결수
	int x, y; // 연결될 좌표
	cin >> netcom >> netnum; // 컴퓨터수와 연결된수 입력
	for (int i = 0; i < netnum; i++) {
		
		cin >> x >> y;
		network[x][y] = 1;
		network[y][x] = 1; //그래프 초기화
	}

	DFS(1); // 1번부터 시작하므로
	cout << infcom -1 <<"\n"; // 1번컴퓨터를 통해 감염됨 컴퓨터의 개수이므로 1번컴퓨터는 제외

	

	return 0;
}


