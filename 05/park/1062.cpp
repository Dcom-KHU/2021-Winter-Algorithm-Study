#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int result = 0;
bool alphabet[26] = { false };
vector<string> vec;


void check_func() {
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		bool check = false;
		int length = vec[i].length();
		for (int j = 0; j < length; j++)
		{
			if (!alphabet[vec[i][j] - 'a']) {
				check = true;
				break;
			}
		}
		if (!check)  // 말할 수 있는 단어
			temp += 1;
	}
	result = max(result, temp);  // 더 많은 경우 갱신
	return;
}

void dfs(int index, int depth) {
	if (k == depth) {  // check 된 알파벳이 k개인 경우
		check_func();  // 단어 벡터 체크 시작
		return;
	}
	else {
		for (int i = index; i < 26; i++) {
			if (!alphabet[i]) {
				alphabet[i] = true;
				dfs(i + 1, depth + 1);  // dfs 방식으로 체크된 알파벳이 k개인 경우 체크
				alphabet[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	if (k < 5) {
		cout << 0 << endl;
		return 0;
	}
	else if (k == 26) {
		cout << n << endl;
		return 0;
	}

	alphabet['a' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	k -= 5;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vec.push_back(str.substr(4, str.length() - 8));
	}

	dfs(0, 0);
	cout << result << endl;
	return 0;
}