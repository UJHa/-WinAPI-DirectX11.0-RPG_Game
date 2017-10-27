#pragma once
#include <Windows.h>
#include<D3DX9.h>
#include<D3D9.h>
#include<vector>
#define RELEASE_COM(x) {if(x){x->Release();x=NULL;}}
#define SAVE_DELETE(x) {if(x){delete x;x=NULL;}}

struct GameTimer;
struct Map;
struct Character;
class GameSystem
{
private:
	static GameSystem* _instance;
	GameSystem();
public:
	~GameSystem();
	static GameSystem* GetInstance();
private:
	D3DPRESENT_PARAMETERS _d3dpp;
	UINT _4xMsaaQuality;
	HWND _hMainWnd;
	LPDIRECT3DDEVICE9 _device3d;
	LPD3DXSPRITE _sprite;

	bool _isFullScreen;
public:
	bool InitSystem(HINSTANCE hInstance, int nCmdShow);
	int Update();
	bool InitDirect3D();
	void CheckDeviceLost();
private:
	int _WindowWidth;
	int _WindowHeight;
	GameTimer* _gameTimer;
	
	Map* _map;
	Character* _character;

//get System
public:
	int GetWindowWidth();
	int GetWindowHeight();
	LPD3DXSPRITE GetSprite();
	LPDIRECT3DDEVICE9 GetDevice3d();
public:
	void MapScrollTest(float moveX, float moveY);
//Input System
public:
	enum eKeyState {
		KEY_DOWN,
		KEY_UP,
	};
private:
	eKeyState _keyState[256];
public:
	void InitInput();
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
};