#include "StateExample.h"
#include "CZMacro.h"
#include "CZGame.h"
#include <windows.h>
#include "CZGameTime.h"

StateExample::StateExample() : m_iCount(0), CZState()
{
}

void StateExample::Init()
{
	Log("State Poster: Init");
	m_iCount = 50;
}

void StateExample::Update()
{
	if (m_iCount <= 1)
	{
		CZGame::GetInstance()->Exit();
		//CZGame::GetInstance()->Pause();
	}
	m_iCount--;
}

void StateExample::Render()
{
	//Log("State Poster: %d : %f", m_iCount, CZGameTime::GetInstance()->getInterval());
	//Sleep(100);
}

void StateExample::Exit()
{
	Log("State Poster: Exit");
}
	