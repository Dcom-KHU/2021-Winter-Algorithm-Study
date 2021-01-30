#include <iostream>
#include <memory.h>
using namespace std;

#define MAXSIZE 4000000+1
#define MAXPRIMECOUNT 283146 //4,000,000���� �Ҽ��� ����
bool isPrime[MAXSIZE]; //�� ���ڵ��� �Ҽ� ���θ� ����
int primeNumbers[283146] = { 0, }; //�Ҽ����� ������� ����
int primeCnt = 0;

//�����佺�׳׽��� ü
void eratos(int n)
{
	for (int i = 2;i <= n;i++)
	{
		if (isPrime[i])
		{
			primeNumbers[primeCnt++] = i;
			if (i <= 2000) //�ش� ���� ���� �� �Ʒ� j=i*i���� i�� MAXSIZE�� ��� �����÷ο� (2000�� MAXSIZE�� ������)
			{
				for (int j = i * i;j <= n;j += i)
					isPrime[j] = false;
			}
		}
	}
}

//���������� ��Ÿ�� �� �ִ� ����� �� ��ȯ
int contSum(int n)
{
	int sum = 0;
	int i = 0; //primeNumbers�� �ε��� �̿��Ͽ� �����ϴ� ����
	int start = 0; //�������� ���� �� (ex. 2+3+5 -> start : 2)
	int ret = 0; //�����

	while (start <= n)
	{
		if (!primeNumbers[i]) //�� �̻� ���س��� �Ҽ��� ���� �� (n���� �۰ų� ���� �Ҽ��� �̹� ��� �������� ��)
			break;
		else
			sum += primeNumbers[i++];
		if (sum >= n)
		{
			if (sum == n) //�������� ����� ���� ã�� ���
				ret++;
			//���� �ʱ�ȭ �� ���� start�������� �ݺ��� ����
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
	memset(isPrime, true, sizeof(isPrime)); //�⺻������ ��� ���� �Ҽ���� ����
	eratos(n);

	cout << contSum(n);

	return 0;
}