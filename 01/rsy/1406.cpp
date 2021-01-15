#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	stack<char> st, tempst, copyst;
	char command, temp;
	int it_num;

	cin >> str >> it_num;

	for (int i = 0; i < str.length(); i++) st.push(str[i]);

	for (int i = 0; i < it_num; i++) {
		cin >> command;
		switch (command) {
		case 'L':
			if (!st.empty()) {//커서 왼쪽은 st, 오른쪽은 tempst에 저장
				tempst.push(st.top());
				st.pop();
			}
			break;
		case 'D':
			if (!tempst.empty()) {
				st.push(tempst.top());
				tempst.pop();
			}
			break;
		case 'B':
			if (!st.empty()) st.pop();
			break;
		case 'P':
			cin >> temp;
			st.push(temp);
			break;
		}
	}

	while (!st.empty()) {
		tempst.push(st.top());
		st.pop();
	}
	while (!tempst.empty()) {
		cout << tempst.top();
		tempst.pop();
	}

	return 0;
}