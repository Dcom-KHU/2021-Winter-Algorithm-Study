#include <iostream>


using namespace std;

int main() {

	ios::sync_with_stdio(false);

	string s;
	cin >> s; // 문자열 입력

	for (int i = 0; i < s.size(); i++)// 문자의 크기만큼 반복
	{
		cout << s[i];

		if ((i + 1) % 10 == 0) // 10번 출력하면 줄바꿈
			cout << endl;

	}

	
	return 0;
	

	
	
}