#include <stdio.h>
using namespace std;

void fill(bool arr[][2188], int col, int row, int length) {
	if (length == 1) { // 재귀의 끝, 배열을 true로 채우고 return
		arr[col][row] = true;
		return;
	}

	// tempLength : 작아지는 사각형의 길이
	int tempLength = length / 3;

	// 재귀를 이용, 가운데를 제외한 부분을 재귀적으로 채운다.
	fill(arr, col, row, tempLength);
	fill(arr, col, row + tempLength, tempLength);
	fill(arr, col, row + tempLength * 2, tempLength);
	fill(arr, col + tempLength, row, tempLength);
	fill(arr, col + tempLength, row + tempLength * 2, tempLength);
	fill(arr, col + tempLength * 2, row, tempLength);
	fill(arr, col + tempLength * 2, row + tempLength, tempLength);
	fill(arr, col + tempLength * 2, row + tempLength * 2, tempLength);
}


int main() {
	bool arr[2188][2188] = { false, };
	size_t length;
	scanf("%d", &length);

	fill(arr, 0, 0, length);

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (arr[i][j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}