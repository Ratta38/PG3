#include <iostream>
#include <stdio.h>

const int MAX_HOURS = 10;
const int kHourlyRate = 1226; // 一般的な時給

// 再帰的な賃金計算＋途中経過表示（累計額同士で比較）
int RecursiveRate(int recursiveHourlyRate, int normalTotal, int recursiveTotal, int hours) {

	if (hours >= MAX_HOURS) {
		return recursiveTotal;
	}

	// 累計額を更新
	normalTotal += kHourlyRate;
	recursiveTotal += recursiveHourlyRate;

	printf("\n=== 賃金比較 (%d時間目) ===\n", hours);
	printf("一般的な賃金の累計額      : %d円\n", normalTotal);
	printf("再帰的な賃金の累計額      : %d円\n", recursiveTotal);

	if (recursiveTotal > normalTotal) {
		printf("→ 再帰的賃金体系のほうが高い\n");
	} else if (recursiveTotal < normalTotal) {
		printf("→ 一般的賃金体系のほうが高い\n");
	} else {
		printf("→ 同額\n");
	}

	// 次の時間の時給を更新
	return RecursiveRate(recursiveHourlyRate * 2 - 50, normalTotal, recursiveTotal, hours + 1);
}

int main() {      
	int recursiveHourlyRate = 100; // 再帰的な初期時給

	RecursiveRate(recursiveHourlyRate, 0, 0, 1);

	return 0;
}