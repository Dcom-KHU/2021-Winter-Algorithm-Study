#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1253: 다이스키!

int n;
int sum = 0;
vector<long long> vec;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());  // 오름차순 정렬

	if (n <= 2) {  // 좋은 수가 나올 수 없다.
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		int left = 0;  // 투포인터
		int right = n - 1;
		int num = vec[i];
		while (left < right) {
			int result = vec[left] + vec[right];
			if (result < num) {  // 작으면 더 큰 수로!
				left++;
			}
			else if (result > num) {  // 크면 더 작은 수로!
				right--;
			}
			else {
				if (i != left && i != right) {  // 둘 다 다르면 ++
					sum++;
					break;
				}
				if (i == left) {  // 같으면 left++
					left++;
				}
				if (i == right) { // 같으면 right--
					right--;
				}
			}
		}
	}

	cout << sum << endl;
}