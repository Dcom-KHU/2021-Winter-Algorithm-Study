#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //숫자 카드의 개수
	cin >> n;

	long long card[100001];
	//카드 숫자 입력 후 정렬
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card + n);

	//최빈값 찾기
	int max = 1; //가장 높은 빈도수
	long long ret = card[0]; //결과값 : 가장 많이 등장한 카드
	int count = 1; //curr가 card[0]부터 시작하므로 1부터 시작

	if (n == 1)
		cout << card[0];
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (card[i] == card[i - 1])
				count++;
			else
				count = 1;
			if (count > max)
			{
				max = count;
				ret = card[i];
			}
		}
		cout << ret;
	}
	return 0;
}