#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string s; // ���ڿ� ����
	cin >> s; // ���ڿ� �Է�

	vector<string> v; // ���̻縦 ������ ����


	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i, s.length()));// ó������ ���� �ڷ� ���� ���̻� ���� ���Ϳ� ����
	}
	sort(v.begin(), v.end()); //���ĺ� ������ ����

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n"; // ���ĵ� ���͸� ���
	}

	return 0;
	

}

