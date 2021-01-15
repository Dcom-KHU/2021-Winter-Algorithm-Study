#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

//n이 소수인지 판별 - 에라토스테네스의 체 사용
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

//n이 팰린드롬인지 판별
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