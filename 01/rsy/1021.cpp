#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int queueSize, extNum, num;
	int index=0,result=0;
	deque<int> que;

	cin >> queueSize>>extNum;
	for (int i = 0; i < queueSize; i++)
		que.push_back(i+1);

	for (int i = 0; i < extNum; i++) {
		cin >> num;

		//2�� 3�� �� �ϳ� �����ϱ� ���� index ����
		for (int i = 0; i < que.size(); i++) {
			if (que[i]== num) {
				index = i;
				break;
			}
		}

		//index�� front�� ������ pop_front
		if (index < que.size() - index)
			while (que.front() != num) {
				que.push_back(que.front());
				que.pop_front();
				result++;
			}
		else //index�� back�� ������ pop_back
			while (que.front() != num) {
				que.push_front(que.back());
				que.pop_back();
				result++;
			}

		que.pop_front();
	}
	cout << result << endl;

	return 0;
}