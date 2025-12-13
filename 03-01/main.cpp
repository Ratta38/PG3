#include "Enemy.h"
#include <memory>

int main() {
	std::unique_ptr<Enemy> enemy_ = std::make_unique<Enemy>();

	// 接近
	enemy_->SetPhase(Phase::APPROACH);
	enemy_->StatePrint();

	// 射撃
	enemy_->SetPhase(Phase::SHOT);
	enemy_->StatePrint();

	// 離脱
	enemy_->SetPhase(Phase::WITHDRAW);
	enemy_->StatePrint();

	return 0;
}