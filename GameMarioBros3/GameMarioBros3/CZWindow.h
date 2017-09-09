//
// Created: 8/9/2017 
// Creater: Zero
// Function: Manager window of Game
//

#ifndef __CZWINDOW_H__
#define __CZWINDOW_H__

#include <windows.h>
#include <windowsx.h>

namespace GameDirectX
{
	class CZWindow
	{
	public:
		CZWindow(int width, int height);
		HWND CreateWindowGame(const char* title, bool fullsreen = false, int windowStyle = 0);
		void DestroyWindowGame();
		HWND getHWND();

	protected:
		static LRESULT CALLBACK WindowProc(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);

		HWND _HandleWindow;
		HINSTANCE _HandleInstance;
		int _iWidth;
		int _iHeight;
		bool _isFullSreen;
	};
}

#endif

