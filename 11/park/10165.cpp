#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> vec;
set<int> result;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a < b) {
			vec.push_back({ a, b, i });
		}
		else {
			vec.push_back({ a - n, b, i });  // 제일 앞에
			vec.push_back({ a, b + n, i });  // 제일 뒤에 하나씩 넣어줌, 원형으로 이루어진 정류장을 펴준다고 생각
		}
	}

	sort(vec.begin(), vec.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {  // 출발이 빠를수록, 도착이 느릴수록
		if (get<0>(a) != get<0>(b))
			return get<0>(a) < get<0>(b);
		else
			return get<1>(a) > get<1>(b);
	});

	int index = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		if (get<1>(vec[index]) < get<1>(vec[i])) {  // index 번째의 노선에 포함이 되어있지 않으면 
			result.insert(get<2>(vec[index]));
			index = i;
		}
	}

	for (int i: result)  // 순서대로 뽑아 줌
	{
		cout << i << ' ';
	}
}