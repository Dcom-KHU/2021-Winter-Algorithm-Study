#include <iostream>
#include <string>
using namespace std;

int main() {
	// 0. cin input
	string str;
	cin >> str;
	cout << str << endl;

	// 1. getline input
	cin.ignore();
	cin.clear();

	getline(cin, str);
	cout << str << endl;

	// 2. string.length()
	int len = str.length();  // string length return
	for (int i = 0; i < len; i++) {
		cout << str[i] << ' ';
	}
	cout << endl;

	// 3. string.find()
	string hello = "hello";
	cout << hello.find('h') << endl;
	cout << hello.find("ell") << endl;
	cout << hello.find('a') << endl;
	cout << (hello.find('a') != string::npos) << endl;
	cout << hello.find('l') << endl;
	cout << hello.find('l', 3) << endl;

	// 4. string.substr(start, length)
	string long_str = "Jose Mourinho Is Sucks";
	cout << long_str.substr(3) << endl;
	cout << long_str.substr(3, 7) << endl;
	cout << long_str.substr(long_str.find(' ') + 1) << endl;
	cout << long_str.substr(long_str.find(' ') + 1, 8) << endl;

	// 5. string.insert(start, string)
	string very = "Very ";
	long_str.insert(long_str.find("Sucks"), very);
	cout << long_str << endl;

	// 6. string.replace(start, length, string)
	string sucks = "SUCKS";
	long_str.replace(long_str.find("Sucks"), 5, sucks);
	cout << long_str << endl;


	// 7. string.erase(start, length)
	long_str.erase(0, 5);
	cout << long_str << endl;

	// 8. string.c_str()
	const char* c_str = long_str.c_str();
	cout << c_str << endl;
}