#include <iostream>

using namespace std;

#define SIZE 128+2

int paper[SIZE][SIZE];
int w = 0, b = 0; // 하얀색, 파란색

void devide(int n, int x, int y) {
	int color = paper[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			// 색이 다른부분이 존재하면 4등분
			if (paper[i][j] != color) {
				devide(n / 2, x, y);			//왼쪽 위
				devide(n / 2, x + n / 2, y);		//왼쪽 아래
				devide(n / 2, x, y + n / 2);		//오른쪽 위
				devide(n / 2, x + n / 2, y + n / 2);	//오른쪽 아래
				return;
			}
		}
	}

	if (color == 1) //blue
		b++;

	else // white
		w++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; //변의 길이
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	devide(N, 0, 0);

	cout << w << '\n' << b;
}