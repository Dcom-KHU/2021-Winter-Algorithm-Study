#include <iostream>
using namespace std;

int main() {
	int n, k, count = 0;
	cin >> n >> k;
	
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];  // 입력
	}
	
	for (int i = n-1; i >= 0; i--) {
		int coin_num = k / arr[i];  // 큰 동전부터
		k -= coin_num * arr[i];
		count += coin_num;
		
		if (k == 0) {
			break;
		}
	}
	
	cout << count << endl;
}