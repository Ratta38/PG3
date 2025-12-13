#pragma once
#include <string>

enum class Phase {
	APPROACH = 0,
	SHOT = 1,
	WITHDRAW = 2,
};

class Enemy {
public:
	void Approach();   // 接近
	void Shot();       // 射撃
	void Withdrawal(); // 離脱

	void StatePrint();// 現在の状態を出力

	void SetPhase(Phase p) { phase_ = p; }

private:
	// メンバ関数のポインタテーブル
	static void (Enemy::* spStateTable[])();

	// 状態
	std::string state_;

	// フェーズ
	Phase phase_ = Phase::APPROACH;
};
