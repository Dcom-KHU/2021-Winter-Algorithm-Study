#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m; //s�� ����
	string s;
	cin >> s; //���ڿ� s

	int ret = 0; //�����
	int count = 0;
	for (int i = 0; i < m - 2; i++)
	{
		if (s[i] == 'I') 
		{
			if ((s[i + 1] == 'O') && (s[i + 2] == 'I'))
			{
				count++; //IOI������ ���ö����� count 1����
				i++;
			}
			else
				count = 0;
		}
		if (count >= n)
			ret++;
	}
	cout << ret;
	return 0;
}