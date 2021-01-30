#include <iostream>
#include <memory.h>
using namespace std;

#define MAXSIZE 4000000+1
#define MAXPRIMECOUNT 283146 //4,000,000이하 소수의 개수
bool isPrime[MAXSIZE]; //각 숫자들의 소수 여부를 저장
int primeNumbers[283146] = { 0, }; //소수들을 순서대로 저장
int primeCnt = 0;

//에라토스테네스의 체
void eratos(int n)
{
	for (int i = 2;i <= n;i++)
	{
		if (isPrime[i])
		{
			primeNumbers[primeCnt++] = i;
			if (i <= 2000) //해당 조건 없을 시 아래 j=i*i에서 i가 MAXSIZE일 경우 오버플로우 (2000은 MAXSIZE의 제곱근)
			{
				for (int j = i * i;j <= n;j += i)
					isPrime[j] = false;
			}
		}
	}
}

//연속합으로 나타낼 수 있는 경우의 수 반환
int contSum(int n)
{
	int sum = 0;
	int i = 0; //primeNumbers에 인덱스 이용하여 접근하는 변수
	int start = 0; //연속합의 시작 값 (ex. 2+3+5 -> start : 2)
	int ret = 0; //결과값

	while (start <= n)
	{
		if (!primeNumbers[i]) //더 이상 구해놓은 소수가 없을 때 (n보다 작거나 같은 소수를 이미 모두 조사했을 때)
			break;
		else
			sum += primeNumbers[i++];
		if (sum >= n)
		{
			if (sum == n) //연속합의 경우의 수를 찾은 경우
				ret++;
			//변수 초기화 후 다음 start지점부터 반복문 시행
			sum = 0;
			start++;
			i = start;
		}
	}
	return ret;
}

int main()
{
	int n; //1<=n<=4,000,000
	cin >> n;
	memset(isPrime, true, sizeof(isPrime)); //기본적으로 모든 수가 소수라고 가정
	eratos(n);

	cout << contSum(n);

	return 0;
}