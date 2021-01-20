#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string s; // 문자열 선언
	cin >> s; // 문자열 입력

	vector<string> v; // 접미사를 저장할 벡터


	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i, s.length()));// 처음부터 점점 뒤로 빼진 접미사 들을 벡터에 저장
	}
	sort(v.begin(), v.end()); //알파벳 순으로 정렬

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n"; // 정렬된 벡터를 출력
	}

	return 0;
	

}

