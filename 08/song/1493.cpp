#include <iostream>
#include <cmath>
using namespace std;

#define N_MAXSIZE 20

long long L, W, H; //�ڽ��� ũ�� �Ӽ�(L:length, W:width, H:height)
int n; //ť���� ������ ����
int a[N_MAXSIZE]; //ť���� ����
int b[N_MAXSIZE]; //ť���� ����
bool flag = true;

int cubeCnt(int n, int l, int w, int h) //l,w,h ũ���� ���ڿ� n��° ť�긦 �󸶳� ���� �� �ִ��� ���
{
	int ret = 0;
	if (n < 0) //�迭 ���� �����
	{
		if ((long long)l * w * h > 0) //���� ���� ������ ���� �� (�����÷ο�� ���� ���� ȸ�� ���� long long �ڷ��� ���)
			flag = false;
		return ret;
	}
	int side = a[n];

	if ((l >= side) && (w >= side) && (h >= side) && (b[n] > 0)) //���� ���� �� ť�갡 ���� ��
	{
		b[n]--; //ť�긦 �ϳ� �Ҹ�
		ret++;
		if ((b[n] == 0) && (n >= 1)) //ť�긦 �� ���������
			n--; //�� ���� ť�� ���

		//ť�긦 �ְ� ���� �� ������ �� �κ����� ����
		ret += cubeCnt(n, side, side, h - side);
		ret += cubeCnt(n, l, w - side, h);
		ret += cubeCnt(n, l - side, side, h);
	}
	else //���� ������ ������ �� ���� ť�� ���
		ret += cubeCnt(n - 1, l, w, h);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> W >> H;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int side;
		cin >> side >> b[i];
		a[i] = pow(2, side); //ť���� �� ���� ����
	}

	int ret = cubeCnt(n - 1, L, W, H); //���� ū ť����� �ֱ� ����

	if (!flag)
		cout << -1;
	else
		cout << ret;

	return 0;
}