#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string str, word;
	int result = 0, i = 0;

	getline(cin, str);
	getline(cin, word);

	//str���� ã�� word�� ũ�� 0
	if (str.length() < word.length())
		cout << 0;
	else{
		while (i < str.length() - word.length() + 1) {
			bool check = true;
			for (int j = 0; j < word.length(); j++) {
				if (str[i + j] != word[j])
					check = false;
			}
			//word�� ��ġ�ϸ� word ���̸�ŭ �ǳʶپ �ٽ� �˻�
			if (check) {
				result++;
				i += word.length();
			}
			else
				i++;
		}
	cout << result;
	}

	return 0;
}