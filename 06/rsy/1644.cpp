#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, sum, result=0;
	vector<int> prime;

	cin >> N;
	int *arr = new int[N+1];

	for (int i = 2; i < N+1; i++)
		arr[i] = i;

	arr[0] = 0; arr[1] = 0;

	//�����佺�׳׽� ü
	for (int i = 2; i < N+1; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = 2 * i; j < N+1; j += i)
			arr[j] = 0;
	}
	
	//N���� �Ҽ��� vector prime�� push
	for (int i = 1; i < N + 1; i++)
		if(arr[i]!=0)
			prime.push_back(arr[i]);

	for (int i = 0; i < prime.size(); i++) {
		sum = 0;
		for (int j = i; j < prime.size(); j++) {
			sum += prime[j];
			if (sum == N) {
				result++;
				break;
			}
			else if (sum > N)//sum�� N���� ũ�� ���� �Ҽ����� ������
				break;
		}
	}

	cout << result;

	delete[] arr;

	return 0;
}