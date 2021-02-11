#include <iostream>
#include <cmath>
using namespace std;

#define N_MAXSIZE 20

long long L, W, H; //박스의 크기 속성(L:length, W:width, H:height)
int n; //큐브의 종류의 개수
int a[N_MAXSIZE]; //큐브의 종류
int b[N_MAXSIZE]; //큐브의 개수
bool flag = true;

int cubeCnt(int n, int l, int w, int h) //l,w,h 크기의 상자에 n번째 큐브를 얼마나 넣을 수 있는지 계산
{
	int ret = 0;
	if (n < 0) //배열 범위 벗어나면
	{
		if ((long long)l * w * h > 0) //아직 남은 공간이 있을 때 (오버플로우로 인한 오류 회피 위해 long long 자료형 사용)
			flag = false;
		return ret;
	}
	int side = a[n];

	if ((l >= side) && (w >= side) && (h >= side) && (b[n] > 0)) //여유 공간 및 큐브가 있을 때
	{
		b[n]--; //큐브를 하나 소모
		ret++;
		if ((b[n] == 0) && (n >= 1)) //큐브를 다 사용했으면
			n--; //더 작은 큐브 사용

		//큐브를 넣고 생긴 빈 공간을 세 부분으로 나눔
		ret += cubeCnt(n, side, side, h - side);
		ret += cubeCnt(n, l, w - side, h);
		ret += cubeCnt(n, l - side, side, h);
	}
	else //여유 공간이 없으면 더 작은 큐브 사용
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
		a[i] = pow(2, side); //큐브의 한 변의 길이
	}

	int ret = cubeCnt(n - 1, L, W, H); //가장 큰 큐브부터 넣기 시작

	if (!flag)
		cout << -1;
	else
		cout << ret;

	return 0;
}