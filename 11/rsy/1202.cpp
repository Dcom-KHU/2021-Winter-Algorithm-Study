#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>&b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K, temp1, temp2;
	long long int result = 0;
	pair<int,int> jewel[300001]; // weight, value ����
	multiset<int> weight; //������ weight ����

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		jewel[i].first = temp1; jewel[i].second = temp2;
	} 
	for (int i = 0; i < K; i++) {
		cin >> temp1;
		weight.insert(temp1);
	}

	sort(jewel,jewel+N,cmp);// ���� ���� ���� ������ ����

	for (int i = 0; i < N; i++) {
		auto it=weight.lower_bound(jewel[i].first);//���� weight������ �� ã��
		if (it != weight.end()) {//���� weight �����̸�
			result += jewel[i].second;// value�� result�� ������
			weight.erase(it);// ���������ν� ����
		}
	}

	cout << result;

	return 0;
}