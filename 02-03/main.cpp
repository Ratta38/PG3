#include <functional>
#include <iostream>
#include <stdio.h>
#include <windows.h>

typedef void (*PFunc)(int, int);

int RandDice() {
	// シード初期化
	srand(static_cast<unsigned int>(time(nullptr)));

	// ランダムな目を出す
	return rand() % 6 + 1;
}

int UserInput() {
	int userGuess;

	printf("丁なら0半なら1を入力\n");
	scanf_s("%d", &userGuess);

	return userGuess;
}

void DelayReveal(std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
	// コールバック関数を呼び出す
	Sleep(delayMs);
	fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess) {
	// 出目が奇数か偶数かを判別
	int judge = (roll % 2 == 0) ? 0 : 1;

	// 結果の出力
	printf("出目は%dでした。\n", roll);

	if (userGuess == judge) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
}

int main() {
	unsigned int delayMs = 3000; // 待ち時間
	int roll = RandDice();       // サイコロの出目
	int userGuess = UserInput(); // ユーザー入力

	// 結果の表示
	PFunc p;
	p = ShowResult;
	DelayReveal(p, delayMs, roll, userGuess);

	return 0;
}