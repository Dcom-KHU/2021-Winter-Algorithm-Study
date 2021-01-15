#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string s;
	cin >> s; // 문자열 입력받음

	stack <char> a; // stack 선언

	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			a.push('(');
			cnt++;  // 왼쪽 괄호를 넣을때마다 막대기의수가 증가
		}
		else // s[i] == ')'
		{
			cnt--; //괄호가 닫혀 레이저가 되거나 막대기의 끝이므로 감소
			if (s[i - 1] == '(') {
				ans += cnt; // 닫는 괄호의 앞에 여는괄호이면 레이저 이므로 현재 막대기 만큼 증가
			}
			else // s[i - 1]  == ')' 
			{
				ans++; // 레이저가 아닌 그냥 막대기 하나가 끝이 났으므로 1증가
			}
		}
	}

	std::cout << ans << "\n";

	return 0;

}
