#pragma once

class Selector;

class Unit{
public:
	Unit() = default;
	void Init(int idef);
	void Update();
	void Draw();

	void Move(int x, int y);
	void MoveEnd(Selector* selector);

private:
	int mapX_=0;
	int mapY_=0;
	int mapSize_=32;
	int id=0;
	bool isSelected_=false;
};