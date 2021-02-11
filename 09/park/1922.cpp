#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int> > edge;
int root[100001];  // 부모 노드 저장
int sum = 0;
int n, m;

int find(int x) {  // 루트 노드 찾기
	if (root[x] == x)
		return x;
	else
		return find(root[x]);
}

int main() {
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++)
	{
		root[i] = i;  // 본인의 최상단 노드를 본인으로 저장
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, a, b });  // 짧은 에지부터 먼저 검사해야 하므로
	}
	sort(edge.begin(), edge.end());  // 길이가 더 작은 값 계산
	
	for (int i = 0; i < m; i++)
	{
		tuple<int, int, int> temp = edge[i];
		int distance = get<0>(temp);
		int a = get<1>(temp);
		int b = get<2>(temp);

		a = find(a);
		b = find(b);

		if (a != b) {  // 둘의 부모 노드가 다르면
			root[a] = b;  // 부모 노드 일치 시킨 후
			sum += distance;  // 길이 합에 추가
		}
	}

	cout << sum << endl;
}