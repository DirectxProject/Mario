#pragma once

#include "CZState.h"
#include "CZMacro.h"

namespace GameDirectX
{
	class CZStateManagement
	{
	public:
		static CZStateManagement* GetInstance()
		{
			if (!_spIntance)
			{
				_spIntance = new CZStateManagement();
			}
			return _spIntance;
		}

		~CZStateManagement();

	protected:
		static CZStateManagement* _spIntance;

	protected:
		CZStateManagement() :_pCurrentState(0), _pNextState(0), _dDelay(0.0f) { }

	protected:
		CZState* _pCurrentState;
		CZState* _pNextState;
		double _dDelay;

	public:
		void Update(bool isPause);
		void SwitchState(CZState* nextState);
	};
}