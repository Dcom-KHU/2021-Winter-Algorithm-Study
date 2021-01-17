#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string a, b; // a : 체크할 문자열 b : 검색할 단어
	int index = 0; // 현재 a에서 찾는위치
	int count = 0; // a에서 b를 찾으면 ++

	getline(cin, a);
	getline(cin, b); // a와 b를 입력받음

	while (true) {
		index = a.find(b, index);
		if (index > a.length()) { // 찾는위치가 문자열 길이 보다 크면의미가 없음
			break;
		}
		count++; // break가 안일어 났으므로 정상적으로 찾음
		index += b.length(); // 찾는 문자열 길이 만큼 더해줌
	}
	cout << count << '\n';

	return 0;
}