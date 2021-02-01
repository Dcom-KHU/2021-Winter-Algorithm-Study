#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

#define MAXSIZE 1000001 //max - min의 최대크기
bool isPrime[MAXSIZE]; //각 숫자들의 소수 여부를 저장 (초깃값 true)
long long squareNum[MAXSIZE] = { 0, }; //소수들의 제곱수들을 저장하는 배열. 2^2 ~ 최대 (10^6)^2까지 저장

bool isSquareMult[MAXSIZE] = { false, }; //각 숫자들이 소수의 제곱수의 배수 여부를 저장. 0번째 index는 min값을 의미.
int squareCnt = 0; //squareNum 배열에 저장된 제곱수들의 개수
int sqrMultCnt = 0; //제곱수로 나누어지는 수들의 개수

int main()
{
	long long min, max;
	cin >> min >> max;
	memset(isPrime, true, sizeof(isPrime));

	//에라토스테네스의 체 이용하여 squareNum 배열 초기화 (문제 조건에 맞게 개량)
	long long n = (long long)sqrt(max);
	for (long long i = 2;i <= n;i++)
	{
		if (isPrime[i])
		{
			squareNum[squareCnt++] = i * i;
			for (long long j = i * i;j <= n;j += i)
				isPrime[j] = false;

		}
	}
	
	for (int i = 0; i < squareCnt;i++) //각 소수의 제곱수들에 대해 min ~ max 사이의 배수를 제거
	{	
		long long start = min; //범위 내에서 최초로 등장하는 제곱수의 배수
		long long quotient = start / squareNum[i]; //start를 제곱수로 나눈 것의 정수부 
		if (start % squareNum[i] != 0) //소수부가 존재할 경우
			quotient++;
		start = quotient * squareNum[i];
		while (start <= max)
		{
			if (isSquareMult[start - min] == false)
				sqrMultCnt++;
			isSquareMult[start - min] = true;
			start += squareNum[i];
		}
	}

	cout << max - min + 1 - sqrMultCnt;

	return 0;
}