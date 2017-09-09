#include "CZGame.h"
#include <iostream>
#include <windows.h>
#include "CZStateManagement.h"
#include "CZMacro.h"

namespace GameDirectX {

	CZGame* CZGame::_spInstance = 0;

	CZGame::CZGame()
	{
		this->_isAlived = true;
		this->_isPaused = false;
		this->_pWindow = NULL;

		this->_spInstance = this;
	}

	CZGame::~CZGame()
	{
		SAFE_DELETE(this->_pWindow);
	}

	void CZGame::Pause()
	{
		_isPaused = true;
	}

	void CZGame::Resume()
	{
		_isPaused = false;
	}

	void CZGame::Exit()
	{
		_isAlived = false;
	}

	void CZGame::Run()
	{
		//Init Game
		if (!this->Init())
		{
			return;
		}

		//Khoi tao GameTime
		CZGameTime::GetInstance()->Update();
		
		//OnDeviceLost() --> Bat su kien

		//Error Handling

		//Main Loop
		MSG msg;
		msg = { 0 };

		// Enter the infinite message loop
		while (true)
		{
			// Check to see if any messages are waiting in the queue
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// translate keystroke messages into the right format
				TranslateMessage(&msg);
				if (msg.hwnd == _pWindow->getHWND())
				{
					// send the message to the WindowProc function
					DispatchMessage(&msg);
				}

				// check to see if it's time to quit
				if (msg.message == WM_QUIT)
					break;
			}
			
			//Process Input

			//Update GameTime
			CZGameTime::GetInstance()->Update();

			//Update and Render
			if (_isAlived) 
			{
				if (_isPaused)
				{
					CZStateManagement::GetInstance()->Update(true);
				}
				else
				{
					CZStateManagement::GetInstance()->Update(false);
				}
			}
			else
			{
				//force clean up current state
				CZStateManagement::GetInstance()->SwitchState(NULL);
				CZStateManagement::GetInstance()->Update(false);
				delete CZStateManagement::GetInstance();
				DestroyWindow(_pWindow->getHWND());
				break;
			}
		}

		this->Destroy();
	}
}