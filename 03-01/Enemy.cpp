#include "Enemy.h"
#include <iostream>

void Enemy::Approach() { state_ = "Approach"; }

void Enemy::Shot() { state_ = "Shot"; }

void Enemy::Withdrawal() { state_ = "Withdraw"; }

void Enemy::StatePrint() {
	(this->*spStateTable[static_cast<size_t>(phase_)])();

	std::cout << state_ << std::endl;
}

void (Enemy::* Enemy::spStateTable[])() = {
    &Enemy::Approach,  // 接近
    &Enemy::Shot,      // 射撃
    &Enemy::Withdrawal // 離脱
};