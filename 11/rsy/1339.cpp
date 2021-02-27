#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a.length() > b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, count, result = 0;
	int arr[27] = { 0, };
	string str;
	vector<int> vec;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		count = 1;
		//arr[알파벳 순서]=10^(string의 길이)
		for (int j = str.size() - 1; j >= 0; j--) {
			arr[str[j]-'A'] += count;
			count *= 10;
		}
	}

	//존재하는 알파벳만 vec에 push
	for (int i = 0; i < 27; i++) {
		if (arr[i] != 0)
			vec.push_back(arr[i]);
	}

	//string 길이 순서대로 정렬
	sort(vec.begin(),vec.end());

	int num = 9;
	//9부터 순차적으로 vec와 곱해서 더해줌
	for (int i = vec.size()-1; i >=0; i--) {
		result += num * vec[i];
		num--;
	}

	cout << result;

	return 0;
}