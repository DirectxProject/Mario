#include "CZWindow.h"
#include "CZMacro.h"

namespace GameDirectX
{
	CZWindow::CZWindow(int width, int height)
	{
		_iWidth = MAX(width, 640);
		_iHeight = MAX(height, 480);
	}

	HWND CZWindow::CreateWindowGame(const char* title, bool fullsreeen, int windowStyle)
	{
		/*
		char consoleTitle[512];
		GetConsoleTitleA(consoleTitle, 512); // Get the title of the console
		HWND hWnd = FindWindowA(consoleTitle, title); // Find the window based on the title
		HINSTANCE hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE); // Get the HINSTANCE from the handle
		*/

		_HandleInstance = GetModuleHandle(NULL);

		if (_HandleWindow == NULL)
		{
			//Step 1: Registering the Window Class
			WNDCLASSEX wc;
			switch (windowStyle)
			{
			default:
			{
				wc.cbSize = sizeof(WNDCLASSEX);
				wc.style = 0;
				wc.lpfnWndProc = WindowProc;
				wc.cbClsExtra = 0;
				wc.cbWndExtra = 0;
				wc.hInstance = _HandleInstance;
				wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
				wc.hCursor = LoadCursor(NULL, IDC_ARROW);
				wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
				wc.lpszMenuName = NULL;
				wc.lpszClassName = "default";
				wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

				if (!RegisterClassEx(&wc))
				{
					MessageBox(NULL, "Window Registration Failed!", "Error!",
						MB_ICONEXCLAMATION | MB_OK);
					return NULL;
				}

				break;
			}
			}

			//create window fullscreen
			if (fullsreeen)
			{
				//Create window FullScreen
			}
			else
			{
				_HandleWindow = CreateWindowEx(
					WS_EX_CLIENTEDGE,
					"default",
					title,
					WS_OVERLAPPEDWINDOW,
					CW_USEDEFAULT, CW_USEDEFAULT, _iWidth, _iHeight,
					NULL, NULL, _HandleInstance, NULL);

				if (_HandleWindow == NULL)
				{
					MessageBox(NULL, "Window Creation Failed!", "Error!",
						MB_ICONEXCLAMATION | MB_OK);
					return NULL;
				}
			}
		}

		ShowWindow(_HandleWindow, SW_SHOW);
		UpdateWindow(_HandleWindow);

		return _HandleWindow;
	}

	void CZWindow::DestroyWindowGame()
	{

	}

	HWND CZWindow::getHWND()
	{
		if (_HandleWindow == NULL)
		{
			MessageBox(NULL, "Window Creation Failed!", "Error!",
				MB_ICONEXCLAMATION | MB_OK);

			return 0;
		}

		return _HandleWindow;
	}

	// this is the main message handler for the program
	LRESULT CZWindow::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		// sort through and find what code to run for the message given
		switch (message)
		{
			// this message is read when the window is closed
		case WM_DESTROY:
		{
			// close the application entirely
			PostQuitMessage(0);
			return 0;
		} break;
		}

		// Handle any messages the switch statement didn't
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}