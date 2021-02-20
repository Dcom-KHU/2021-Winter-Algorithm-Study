#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(4); //�Ҽ��� 4��°�ڸ����� ���
	
	map<string, int> tree;
	int cnt = 0; //map�� ����� ������ �� �׷� ��
	string str;
	while (true)
	{
		getline(cin, str);
		if (str == "")
			break;
		tree[str]++;
		cnt++;
	}

	for (auto t : tree)
		cout << t.first << " " << 100 * (double)(t.second) / cnt << "\n";

	return 0;
}