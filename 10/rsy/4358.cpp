#include <iostream>
#include<iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> pair;
	string name;
	int count=0;

	while (getline(cin,name)) {
		if (name == "") break;
		count++;
		pair[name]++;
	}

	for (auto i : pair) {
		cout << i.first<<' ';
		cout.precision(4);
		cout << fixed<<double(i.second) / double(count) * double(100)<<'\n';
	}


	return 0;
}

