#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int alpha[26] = { 0 }; // ���ĺ� ���� Ƚ���� ���� �ϴ� �迭 ����

	string str; 
	cin >> str; // �ܾ��Է�

	

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			alpha[str[i] - 32 - 65]++;
		}
		else // �빮���ΰ��
		{
			alpha[str[i] - 65]++;
		}
	}

	int max = 0;
	int cnt = 0, ans = 0;
	for (int i = 0; i < 26; i++)
	{
		// ���� ���� ���� ���ĺ� ���ϱ�
		if (max < alpha[i])
		{
			max = alpha[i];
			ans = i;
		}
	}

	for (int j = 0; j < 26; j++)
	{
		// ���� ���� ���� ���ĺ��� ���� �� �����ϴ��� �˻�
		for (int i = j + 1; i < 26; i++)
		{
			if (max == alpha[j] && max == alpha[i])
				cnt++;
		}
	}

	// ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ���
	if (cnt > 0)
	{
		cout << "?";
	}
	else
	{
		// ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ���
		cout << (char)(ans + 65);
	}

	return 0;
}


