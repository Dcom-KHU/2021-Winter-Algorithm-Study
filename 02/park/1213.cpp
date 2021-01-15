#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {  // 유클리드 호제법
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	string str;
	cin >> str;

	int alphabet[26] = { 0 };  // 알파벳 담는 변수
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		alphabet[str[i] - 'A']++;  // 알파벳 담는 과정
	}

	if (length % 2 == 0) {  // 길이가 짝수
		bool check = false;
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] % 2 != 0) {  // 짝수가 아닌게 있다면 버그
				check = true;
				break;
			}
		}
		if (check)
			cout << "I'm Sorry Hansoo" << endl;
		else {
			for (int i = 0; i < 26; i++)  // 사전순 출력
			{
				for (int j = 0; j < alphabet[i] / 2; j++)
				{
					cout << (char)('A' + i);
				}
			}
			for (int i = 25; i >= 0; i--)  // 사전역순 출력
			{
				for (int j = 0; j < alphabet[i] / 2; j++)
				{
					cout << (char)('A' + i);
				}
			}
		}
	}
	else {  // 길이가 홀수일때
		int flag = -1; // idx
		bool check = false;
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] % 2 == 1) {
				if (flag != -1) {  // 이미 홀수 갯수를 가진 알파벳이 있을때
					check = true;
					break;
				}
				else {  // 홀수 갯수를 가진 알파벳은 따로 저장
					flag = i;
					alphabet[i]--;
				}
			}
		}

		if (check)
			cout << "I'm Sorry Hansoo" << endl;
		else {  
			for (int i = 0; i < 26; i++)  // 사전순 출력
			{
				for (int j = 0; j < alphabet[i] / 2; j++)
				{
					cout << (char)('A' + i);
				}
			}
			cout << (char)('A' + flag);  // 홀수개 처리
			for (int i = 25; i >= 0; i--)  // 사전역순 출력
			{
				for (int j = 0; j < alphabet[i] / 2; j++)
				{
					cout << (char)('A' + i);
				}
			}
		}
	}
	cout << endl;
}