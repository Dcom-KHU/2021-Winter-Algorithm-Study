#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string n; //문자열 초깃값
	getline(cin, n);
	stack<char> left, right; //커서 기준 왼쪽, 오른쪽 스택
	for (int i = 0; i < n.length(); i++)
		left.push(n[i]);
	int m; //명령어의 개수
	cin >> m;
	char op; //명령어
	char ch; //추가 입력문자
	for (int i = 0; i < m; i++)
	{
		cin >> op;
		switch (op)
		{
		case 'L':
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B':
			if (!left.empty())
				left.pop();
			break;
		case 'P':
			cin >> ch;
			left.push(ch);
			break;
		}
	}

	// 순서대로 출력하기 위해 모든 문자 right로 이동
	int ls = left.size();
	for (int i = 0; i < ls; i++)
	{
		right.push(left.top());
		left.pop();
	}
	int rs = right.size();
	for (int i = 0; i < rs; i++)
	{
		cout << right.top();
		right.pop();
	}
	return 0;
}