#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int num;
	cin >> num;

	stack<int> s;
	string msg;
	int n;

	for(int i = 0; i<  num; i++) {
		cin >> msg;
		if (msg == "push") {
			cin >> n;
			s.push(n);
		}
		else if (msg == "pop") {
			if (s.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (msg == "size") {
			cout << s.size() << "\n";
		}
		else if (msg == "empty") {
			cout << s.empty() << "\n";
		}
		else if (msg == "top") {
			if (s.empty()) {
				cout << "-1" << "\n";
			}
			else cout << s.top() << "\n";
		}

	}

	return 0;
}
