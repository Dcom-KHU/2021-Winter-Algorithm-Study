#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string n; //���ڿ� �ʱ갪
	getline(cin, n);
	stack<char> left, right; //Ŀ�� ���� ����, ������ ����
	for (int i = 0; i < n.length(); i++)
		left.push(n[i]);
	int m; //��ɾ��� ����
	cin >> m;
	char op; //��ɾ�
	char ch; //�߰� �Է¹���
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

	// ������� ����ϱ� ���� ��� ���� right�� �̵�
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