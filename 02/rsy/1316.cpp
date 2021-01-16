#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	int N,result=0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		bool check = true;
		for(int j=0;j<word.length();j++)
			for(int k=0;k<j;k++)
				//이어지지도 않고 알파벳이 중복된 경우
				if (word[j - 1] != word[j] && word[j] == word[k]) {
					check = false;
					break;
				}

		if (check)
			result++;
	}
	cout << result;
}