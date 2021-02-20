#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int n; //수의 개수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int num;
	for (int i = 0;i < n;i++)
	{
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());

	int ret = 0; //결과값
	for (int i = 0;i < n;i++)
	{
		int left = 0;
		int right = n-1;
		while (left < right)
		{
			int check = a[left] + a[right];
			if (check == a[i]) //a[i]의 조합을 찾은 경우
			{
				if ((i != left) && (i != right))//자기 자신을 더하는 경우 제외
				{
					ret++;
					break;
				}
				else if (i == left)
					left++;
				else if (i == right)
					right--;
			}
			else
			{
				if (check > a[i]) //찾아야하는 값보다 큰 경우
					right--;
				if (check < a[i]) //찾아야하는 값보다 작은 경우
					left++;
			}
		}
	}

	cout << ret;
	return 0;
}