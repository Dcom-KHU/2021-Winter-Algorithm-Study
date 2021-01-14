#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;

	long long result = 0;
	int temp = 1;  // 맨 밑의 값을 계산 하기 위함
	bool check = false;  // 유효 검사

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		// expression check
		else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
			check = true;
			break;
		}
		else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
			check = true;
			break;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(')
				result += temp;
			s.pop();
			temp /= 2;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[')
				result += temp;
			s.pop();
			temp /= 3;
		}
	}

	if (check || !s.empty())
		cout << 0 << '\n';
	else
		cout << result << '\n';

	return 0;
}