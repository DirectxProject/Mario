#pragma once

#include "CZWindow.h"
#include "CZGameTime.h"

namespace GameDirectX
{
	class CZGame
	{

	public:
		static CZGame* GetInstance() { return _spInstance; }
		virtual ~CZGame();
		virtual void Run();
		virtual void Exit();
		virtual void Pause();
		virtual void Resume();
		bool IsAlive() { return _isAlived; }
		bool IsPause() { return _isPaused; }

	protected:
		CZGame();
		static CZGame* _spInstance;
		virtual bool Init() = 0;
		virtual void Destroy() = 0;

	protected:
		CZWindow* _pWindow;

	private:
		bool _isAlived;
		bool _isPaused;

	};

}