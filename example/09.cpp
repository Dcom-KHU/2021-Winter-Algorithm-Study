#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> vec = { 4, 1, 2, 5, 3, 6, 9, 8 };
	sort(vec.begin(), vec.end(), less<int>());  // == sort(vec.begin(), vec.end())
	for (int i: vec)
	{
		cout << i << ' ';
	}
	cout << endl;

	sort(vec.begin(), vec.end(), greater<int>());
	for (int i : vec)
	{
		cout << i << ' ';
	}
	cout << endl << endl;

	vector<pair<int, int> > vec2 = { {1, 3}, {1, 2}, {3, 2}, {2, 2} };
	sort(vec2.begin(), vec2.end(), less<pair<int, int> >());
	for (pair<int, int> i: vec2)
	{
		cout << i.first << ' ' << i.second << endl;
	}
}