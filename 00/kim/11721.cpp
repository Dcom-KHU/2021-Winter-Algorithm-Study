#include <iostream>


using namespace std;

int main() {

	ios::sync_with_stdio(false);

	string s;
	cin >> s; // ���ڿ� �Է�

	for (int i = 0; i < s.size(); i++)// ������ ũ�⸸ŭ �ݺ�
	{
		cout << s[i];

		if ((i + 1) % 10 == 0) // 10�� ����ϸ� �ٹٲ�
			cout << endl;

	}

	
	return 0;
	

	
	
}