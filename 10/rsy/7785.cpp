#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	string name, status;
	stack<string> st;
	map<string, int> pair;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name>>status;
		if (status == "enter")
			pair[name] = 1;
		else
			pair[name] = 0;
	}

	for (auto i : pair) {
		if (i.second == 1)
			st.push(i.first);
	}

	while (!st.empty()) {
		cout << st.top() << '\n';
		st.pop();
	}

	return 0;
}

