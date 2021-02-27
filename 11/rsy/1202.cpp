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
	pair<int,int> jewel[300001]; // weight, value 저장
	multiset<int> weight; //가방의 weight 저장

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		jewel[i].first = temp1; jewel[i].second = temp2;
	} 
	for (int i = 0; i < K; i++) {
		cin >> temp1;
		weight.insert(temp1);
	}

	sort(jewel,jewel+N,cmp);// 보석 무게 작은 수부터 정렬

	for (int i = 0; i < N; i++) {
		auto it=weight.lower_bound(jewel[i].first);//가방 weight이하인 수 찾음
		if (it != weight.end()) {//가방 weight 이하이면
			result += jewel[i].second;// value값 result에 더해줌
			weight.erase(it);// 더해줌으로써 지움
		}
	}

	cout << result;

	return 0;
}