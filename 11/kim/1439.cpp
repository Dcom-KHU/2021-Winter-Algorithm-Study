#include <iostream>
using namespace std;

int main() {
	string str;

	cin >> str;

	int rev0 = 0; //0�� �������� Ƚ��
	int rev1 = 0; //1�� �������� Ƚ��

	if (str[0] == '0') //ó���� 0���� 1����
		rev0++;
	else
		rev1++;

	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1]) {//���� ���ڿ� ���繮�ڰ� �ٸ���� 
			if (str[i] == '1')
				rev1++;
			else
				rev0++;
		}
	}

	if (rev1 > rev0)
		cout << rev0;
	else
		cout << rev1;

	cout << "\n";

}
