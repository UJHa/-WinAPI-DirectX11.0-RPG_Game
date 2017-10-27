#pragma once
#include<Windows.h>
#include<vector>
#include"Component.h"
struct Sprite;
class Character : public Component
{
private:
	std::vector<Sprite*> _spriteList;

	float _x;
	float _y;

	float _deltaX;
	float _deltaY;

	int _tileX;
	int _tileY;
public:
	Character(LPCWSTR name);
	~Character();

	void Init();
	void DInit();
	void Update(float deltaTime);
	void Render();
	void Release();
	void Reset();
	// transform
public:
	void MoveDeltaPosition(float deltaX, float deltaY);
	//AI
public:
	virtual void UpdateAI() = 0;
	//Move
public:
	enum eDirection {
		LEFT,RIGHT,UP,DOWN
	};
protected:
	bool _isMoving;
private:
	float _moveTime;
	float _movingDuration;
	eDirection _currentDirection;
	float _targetX;
	float _targetY;
	float _moveDistancePerTimeX;
	float _moveDistancePerTimeY;
public:
	void InitMove();
	void MoveStart(eDirection direction);
	void UpdateMove(float deltaTime);
};