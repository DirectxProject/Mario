#pragma once

#include "CZState.h"

using namespace GameDirectX;

class StateExample :public CZState
{
public:
	StateExample();
	~StateExample() {}

	void Init();
	void Update();
	void Render();
	void Exit();

private:
	int m_iCount;
};
