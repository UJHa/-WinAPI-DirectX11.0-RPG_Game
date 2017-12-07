#pragma once
#include<string>
using namespace std;
class Component;
class Stage;
class Unit
{
public:
	Unit(Stage* stage);
	~Unit();

protected:
	Stage* _stage;
	wstring _name;
	int _lifeNpcCount;
public:
	void SetName(wstring componentName);
	virtual void CreateComponents() {}
	virtual Component* CreateLifeNPC(wstring scriptName, wstring pngName) { return NULL; }
};