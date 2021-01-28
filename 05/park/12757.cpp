#include <iostream>
#include <map>
#include <utility>
using namespace std;

int n, m, k;  // 데이터 갯수, 명령 갯수, 근접한 Key까지의 거의 제한
map<int, int> dict;

int find_key(int key) {
	map<int, int>::iterator lower_iter(dict.lower_bound(key));  // key 보다 크거나 같음

	if (lower_iter == dict.end()) {  // key가 오른쪽 끝
		map<int, int>::reverse_iterator last_iter = dict.rbegin();
		if (key - last_iter->first <= k) {
			return last_iter->first;
		}
		else {
			return -1;
		}
	}
	else if (lower_iter->first == key) // 같은 경우 검사
		return key;
	else if (lower_iter == dict.begin()) {  // key가 왼쪽 끝
		if (lower_iter->first - key <= k)
			return lower_iter->first;
		else
			return -1;
	}
	

	map<int, int>::iterator left_iter = --lower_iter;
	++lower_iter;

	int left_key = left_iter->first;
	int left_value = left_iter->second;

	int lower_key = lower_iter->first;
	int lower_value = lower_iter->second;

	if (key - left_key < lower_key - key && key - left_key <= k)  // 왼쪽 차가 작음
		return left_key;
	else if (key - left_key > lower_key - key && lower_key - key <= k)  // 오른쪽 차가 작음
		return lower_key;
	else if ((key - left_key == lower_key - key && lower_key - key <= k))  // 차 똑같음
		return -2;
	else  // 어느쪽의 차도 k 보다 큼
		return -1;
}

int main() {
	cin >> n >> m >> k;
	// 변수 초기화
	for (int i = 0; i < n; i++)
	{
		int key, value;
		cin >> key >> value;
		dict.insert(make_pair(key, value));
	}

	// 명령
	for (int i = 0; i < m; i++)
	{
		int macro, key, value;
		cin >> macro;

		if (macro == 1) {
			cin >> key >> value;
			dict.insert(make_pair(key, value));
		}
		else if (macro == 2) {
			cin >> key >> value;
			int temp_key = find_key(key);

			if (temp_key != -1 && temp_key != -2) {
				dict[temp_key] = value;
			}
		}
		else {
			cin >> key;
			int temp_key = find_key(key);

			if (temp_key == -1) {
				cout << -1 << '\n';
			}
			else if (temp_key == -2) {
				cout << '?' << '\n';
			}
			else {
				cout << dict[temp_key] << '\n';
			}
		}
	}
}