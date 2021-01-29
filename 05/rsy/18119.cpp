#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<bitset<26>> word;
vector<bitset<26>> temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	int N, M, o, result;
	char x;

	cin >> N >> M;
	word.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> str;
		for(char c : str)
			word[i][c-'a'] = 1;
	}

	temp = word;

	for (int i = 0; i < M; i++) {
		cin >> o >> x;
		
		if (o == 1) {
			for (int j = 0; j < N; j++)
				if (temp[j][x - 'a'] == 1)
					word[j][x - 'a'] = 0;
		}
		else {
			for (int j = 0; j < N; j++)
				if (temp[j][x - 'a'] == 1)
					word[j][x - 'a'] = 1;
		}

		result = 0;
		for (int j = 0; j < N; j++)
			if (temp[j] == word[j])
				result++;

		cout << result<<'\n';
	}

	return 0;
}