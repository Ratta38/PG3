#pragma once
#include "Unit.h"

class Selector{
public:
	int mapX_;
	int mapY_;
	int mapSize_;

	int selectMode_;

	Unit* unit_;
	Unit* selectedUnit_;

private:
	Selector();

	void Init();
	void Update();
	void Draw();

	void Move(int x,int y);
	void SelectUnit();
};