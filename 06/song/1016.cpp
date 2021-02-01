#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

#define MAXSIZE 1000001 //max - min�� �ִ�ũ��
bool isPrime[MAXSIZE]; //�� ���ڵ��� �Ҽ� ���θ� ���� (�ʱ갪 true)
long long squareNum[MAXSIZE] = { 0, }; //�Ҽ����� ���������� �����ϴ� �迭. 2^2 ~ �ִ� (10^6)^2���� ����

bool isSquareMult[MAXSIZE] = { false, }; //�� ���ڵ��� �Ҽ��� �������� ��� ���θ� ����. 0��° index�� min���� �ǹ�.
int squareCnt = 0; //squareNum �迭�� ����� ���������� ����
int sqrMultCnt = 0; //�������� ���������� ������ ����

int main()
{
	long long min, max;
	cin >> min >> max;
	memset(isPrime, true, sizeof(isPrime));

	//�����佺�׳׽��� ü �̿��Ͽ� squareNum �迭 �ʱ�ȭ (���� ���ǿ� �°� ����)
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
	
	for (int i = 0; i < squareCnt;i++) //�� �Ҽ��� �������鿡 ���� min ~ max ������ ����� ����
	{	
		long long start = min; //���� ������ ���ʷ� �����ϴ� �������� ���
		long long quotient = start / squareNum[i]; //start�� �������� ���� ���� ������ 
		if (start % squareNum[i] != 0) //�Ҽ��ΰ� ������ ���
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