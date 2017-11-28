#pragma once
#include"Component.h"
using namespace std;
class Sprite;
class TileObject : public Component
{
private:
	Sprite* _sprite;
	float _posX;
	float _posY;
public:
	TileObject(wstring name, Sprite* sprite);
	virtual ~TileObject();

	virtual void Init();
	virtual void DInit();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Release();
	virtual void Reset();

	void MoveDeltaPosition(float deltaX, float deltaY);
	void SetPosition(float posX, float posY);
};