#include <iostream>

using namespace std;

int main() {
	int N, M, caseNum, a, b;
	cin >> caseNum;

	while (caseNum--) {
		cin >> N >> M;
		
		for (int i = 0; i < M; i++)
			cin >> a >> b;
		
		cout << N - 1 << '\n';
	}
}

