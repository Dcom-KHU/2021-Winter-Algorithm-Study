#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(4); //소수점 4번째자리까지 출력
	
	map<string, int> tree;
	int cnt = 0; //map에 저장될 나무의 총 그루 수
	string str;
	while (true)
	{
		getline(cin, str);
		if (str == "")
			break;
		tree[str]++;
		cnt++;
	}

	for (auto t : tree)
		cout << t.first << " " << 100 * (double)(t.second) / cnt << "\n";

	return 0;
}