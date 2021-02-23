#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> vec;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	set<int> s;  // 멀티탭 현황
	int sum = 0;  // 멀티탭 간 횟수
	int index = 0;  // 인덱스
	while (s.size() != n) {  // 멀티탭을 다 사용할 때 까지 사용
		s.insert(vec[index++]);
	}
	
	while (index < k) {  
		if (s.find(vec[index]) == s.end()) {  // 새로 꼽아야 할때
			set<int> n_s(s);
			for (int i = index + 1; i < k; i++)  // 다 쓸일이 있는지 check
			{
				if (n_s.find(vec[i]) != n_s.end()) {
					n_s.erase(vec[i]);
				}
			}

			if (n_s.size() > 0) {  // 어떤 놈은 이제 안쓰네요?
				s.erase(*n_s.begin());
				s.insert(vec[index]);
				sum++;
			}
			else {  // 처음 등장하는 시간이 가장 늦은 플러그
				set<int> nn_s(s);
				for (int i = index + 1; i < k; i++)
				{
					if (nn_s.size() == 1) {
						s.erase(*nn_s.begin());
						s.insert(vec[index]);
						sum++;
						break;
					}
					if (nn_s.find(vec[i]) != nn_s.end()) {
						nn_s.erase(vec[i]);
					}
				}
				
			}
		}
		index++;
	}

	cout << sum << '\n';
	return 0;
}