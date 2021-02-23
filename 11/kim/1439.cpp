#include <iostream>
using namespace std;

int main() {
	string str;

	cin >> str;

	int rev0 = 0; //0이 뒤집히는 횟수
	int rev1 = 0; //1이 뒤집히는 횟수

	if (str[0] == '0') //처음이 0인지 1인지
		rev0++;
	else
		rev1++;

	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1]) {//전의 문자와 현재문자가 다를경우 
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
