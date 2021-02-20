#include <iostream>
#include <string>
#include <map>
using namespace std;

int root[200001] = { 0 };
int friendNum[200001] = { 0 };

int find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);  // 맨 위의 부모에 직접 연결
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int f;
		cin >> f;
		int index = 1;

		for (int i = 1; i <= 2 * f; i++)  // 2 * ㄹ 인 이유는 시간 절약
		{
			root[i] = i;
			friendNum[i] = 1;  // 본인만 있으니까
		}

		map<string, int> keyMap;  // key - int 쌍이 있는 map
		
		for (int i = 0; i < f; i++)
		{
			string first, second;
			cin >> first >> second;

			if (keyMap.find(first) == keyMap.end()) {  // 없으면 추가
				keyMap.insert({ first, index++ });
			}
			if (keyMap.find(second) == keyMap.end()) {
				keyMap.insert({ second, index++ });
			}

			int a = find(keyMap[first]);  // 루트 노드 탐색
			int b = find(keyMap[second]);

			if (a != b) {  // 다르면 합쳐야지
				root[a] = b;  // 루트 지정
				friendNum[b] += friendNum[a];  // 부모 노드에 자식 노드의 친구 수 추가
				friendNum[a] = 1;  // 자식 노드는 1로 만듦
			}

			cout << friendNum[b] << '\n';  // 출력
		}
	}

	return 0;
}