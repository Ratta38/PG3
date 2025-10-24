#include <iostream>
#include <stdio.h>

const int MAX_HOURS = 10;
const int kKourlyRate = 1226;

// 再帰的な賃金計算＋途中経過表示
int RecursiveRate(int hourlyRate, int recursiveHourlyRate, int hours) {
	if (hours >= MAX_HOURS) {
		return recursiveHourlyRate;
	}

	printf("\n=== 時給比較 (%d時間目) ===\n", hours);
	printf("一般的な時給で儲けた額      : %d円\n", hourlyRate);
	printf("再帰的な時給で儲けた額      : %d円\n", recursiveHourlyRate);

	if (recursiveHourlyRate > hourlyRate) {
	    printf("再帰的時給で儲けた額の方が高い\n");
	} else if (recursiveHourlyRate < hourlyRate) {
	    printf("一般的時給で儲けた額の方が高い\n");
	} else {
	    printf("同額\n");
	}

	return RecursiveRate(hourlyRate + kKourlyRate, recursiveHourlyRate * 2 - 50, hours + 1);
}

int main() {
	// 一般的な賃金体系での時給
	int hourlyRate = 1226;

	// 再帰的な賃金体系での初期時給
	int recursiveHourlyRate = 100;

	// 2つの体系での最終的な時給
	int finalRate = RecursiveRate(hourlyRate, recursiveHourlyRate, 1);

	return 0;
}
