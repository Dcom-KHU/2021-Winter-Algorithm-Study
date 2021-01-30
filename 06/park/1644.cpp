#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int result = 0;
bool not_prime[4000001] = { false };
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 에레토스테네스의 채
	for (int i = 2; i <= 2000; i++)
	{
		if (!not_prime[i]) {
			for (int j = i * i; j <= 4000000; j += i)
			{
				not_prime[j] = true;
			}
		}
	}

	// 소수 push
	for (int i = 2; i <= 4000001; i++)
	{
		if (!not_prime[i])
			vec.push_back(i);
	}

	cin >> n;

	// 변수 초기화
	int left = 0, right = 0;
	int sum = vec[0];
	int size = vec.size();

	while (left <= right)
	{
		if (sum > n) {
			sum -= vec[left];
			left += 1;
		}
		else if (sum < n) {
			right += 1;
			sum += vec[right];
		}
		else {
			result += 1;
			right += 1;
			sum += vec[right];
		}
	}

	cout << result << endl;

	return 0;
}