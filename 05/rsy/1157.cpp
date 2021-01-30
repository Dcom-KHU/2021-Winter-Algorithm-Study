#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string word;
	int arr[26];
	int temp[26];

	cin >> word;

	for (int i = 0; i < 26; i++)
		arr[i] = 0;

	for (int i = 0; i < word.length(); i++) {
		if (word[i] < 'a')
			arr[word[i] - 'A']++;
		else
			arr[word[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		temp[i] = arr[i];

	sort(arr, arr + 26);

	if (arr[24] == arr[25])
		cout << '?';
	else
		for(int i=0;i<26;i++)
			if (temp[i] == arr[25]) {
				cout << char(65+i);
				break;
			}

	return 0;
}

