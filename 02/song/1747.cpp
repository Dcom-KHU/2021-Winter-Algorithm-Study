#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

//n�� �Ҽ����� �Ǻ� - �����佺�׳׽��� ü ���
bool isPrime(int n)
{
	int sqrtN = sqrt(n);
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		for (int i = 3; i <= sqrtN; i += 2)
		{
			if (n % i == 0)
				return false;
		}
	}
	return true;
}

//n�� �Ӹ�������� �Ǻ�
bool isPalindrome(int n)
{
	string nStr = to_string(n);
	string revNStr = nStr;
	reverse(revNStr.begin(), revNStr.end());
	if (nStr.compare(revNStr) == 0)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	while (true)
	{
		if (isPrime(n) && isPalindrome(n))
		{
			cout << n;
			break;
		}
		else
			n++;
	}
	return 0;
}