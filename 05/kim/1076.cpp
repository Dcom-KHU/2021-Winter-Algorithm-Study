#include <iostream>
#include <string>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	string colors[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	// 배열에 저장하면 값과 index를 대응 시킬수 있음

	string str1, str2, str3; // 입력받을 문자열

	long long a, b, c;

	cin >> str1;

	cin >> str2;

	cin >> str3;

	for (int i = 0; i < 10; i++) {
		if (colors[i] == str1)
			a = i; //입력 값을 배열에서 찾아서 저장
	}
	for (int j = 0; j < 10; j++) {
		if (colors[j] == str2)
			b = j;
	}

	for (int k = 0; k < 10; k++){
		if (colors[k] == str3)
			c = k;
}

	long long temp = 1;

	for (int i = 0; i < c; i++){
		temp *= 10;
		// 곱의 값이 10의 index 제곱 값과 같으므로
	}
	long long result = ((a * 10) + b) * temp;

	cout << result << '\n';

	return 0;

}

​