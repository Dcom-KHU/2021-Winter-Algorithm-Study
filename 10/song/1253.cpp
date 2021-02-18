#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int n; //���� ����

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

	int ret = 0; //�����
	for (int i = 0;i < n;i++)
	{
		int left = 0;
		int right = n-1;
		while (left < right)
		{
			int check = a[left] + a[right];
			if (check == a[i]) //a[i]�� ������ ã�� ���
			{
				if ((i != left) && (i != right))//�ڱ� �ڽ��� ���ϴ� ��� ����
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
				if (check > a[i]) //ã�ƾ��ϴ� ������ ū ���
					right--;
				if (check < a[i]) //ã�ƾ��ϴ� ������ ���� ���
					left++;
			}
		}
	}

	cout << ret;
	return 0;
}