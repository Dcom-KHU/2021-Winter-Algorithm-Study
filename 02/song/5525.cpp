#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m; //s의 길이
	string s;
	cin >> s; //문자열 s

	int ret = 0; //결과값
	int count = 0;
	for (int i = 0; i < m - 2; i++)
	{
		if (s[i] == 'I') 
		{
			if ((s[i + 1] == 'O') && (s[i + 2] == 'I'))
			{
				count++; //IOI패턴이 나올때마다 count 1증가
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