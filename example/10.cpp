#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> vec = { 4, 1, 2, 5, 3, 6, 9, 8, 7 };
	
	// Linear Search
	for (int i = 0; i < 10; i++)
	{
		if (vec[i] == 7) {
			cout << i << endl;
			break;
		}
	}

	// Binary Search
	sort(vec.begin(), vec.end());

	int left = 0;
	int right = 10 - 1;
	int mid = (left + right) / 2;

	while (left <= right) {
		if (vec[mid] == 7) {
			cout << mid << endl;
			break;
		}
		else if (vec[mid] < 7) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}

	// Hash Table
	int hashTable[10] = { 0 };
	int elements[10] = { 7, 68, 140, 50, 98, 76, 39, 9, 100, 99 };

	// Insert
	for (int e : elements) {
		int index = e % 10;
		while (hashTable[index] != 0) {
			index = (index + 1) % 10;
		}
		hashTable[index] = e;
	}

	// Search
	for (int e : elements) {
		int index = e % 10;
		while (hashTable[index] != e) {
			index = (index + 1) % 10;
		}
		cout << hashTable[index] << "-> " << index << endl;
	}
}