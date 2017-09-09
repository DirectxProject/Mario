#pragma once
#include "CZGame.h"

using namespace GameDirectX;

class Example : public GameDirectX::CZGame
{
public:
	Example() : GameDirectX::CZGame() {}
	~Example(){}

protected:
	bool Init();
	void Destroy();
};

