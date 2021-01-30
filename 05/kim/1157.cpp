#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int alpha[26] = { 0 }; // 알파벳 나온 횟수를 저장 하는 배열 선언

	string str; 
	cin >> str; // 단어입력

	

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			alpha[str[i] - 32 - 65]++;
		}
		else // 대문자인경우
		{
			alpha[str[i] - 65]++;
		}
	}

	int max = 0;
	int cnt = 0, ans = 0;
	for (int i = 0; i < 26; i++)
	{
		// 가장 많이 사용된 알파벳 구하기
		if (max < alpha[i])
		{
			max = alpha[i];
			ans = i;
		}
	}

	for (int j = 0; j < 26; j++)
	{
		// 가장 많이 사용된 알파벳이 여러 개 존재하는지 검사
		for (int i = j + 1; i < 26; i++)
		{
			if (max == alpha[j] && max == alpha[i])
				cnt++;
		}
	}

	// 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력
	if (cnt > 0)
	{
		cout << "?";
	}
	else
	{
		// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력
		cout << (char)(ans + 65);
	}

	return 0;
}


