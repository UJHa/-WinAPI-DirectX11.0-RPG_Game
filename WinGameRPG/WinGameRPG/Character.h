#pragma once
#include<Windows.h>
#include<vector>
#include<string>
#include"Component.h"
class Sprite;
class Character : public Component
{
protected:
	float _x;
	float _y;
	std::wstring _scrpitName;
	std::wstring _pngName;

	int _attackPoint;
	int _hp;
private:
	std::vector<Sprite*> _spriteList;

	float _deltaX;
	float _deltaY;
public:
	Character(LPCWSTR name, LPCWSTR scriptName, LPCWSTR pngName);
	virtual ~Character();

	void Init();
	void DInit();
	void Update(float deltaTime);
	void Render();
	void Release();
	void Reset();
	// transform
public:
	virtual void MoveDeltaPosition(float deltaX, float deltaY);
	void SetPosition(float posX, float posY);
	//AI
public:
	virtual void UpdateAI();
	//Move
public:
	enum eDirection {
		LEFT,RIGHT,UP,DOWN,NONE,
	};
protected:
	bool _isMoving;
	float _moveTime;
	float _movingDuration;
	eDirection _currentDirection;
	float _targetX;
	float _targetY;
public:
	void InitMove();
	void MoveStart(eDirection direction);
	virtual void UpdateMove(float deltaTime);
};