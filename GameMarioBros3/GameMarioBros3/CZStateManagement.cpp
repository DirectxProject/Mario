#include "CZStateManagement.h"
#include "CZGameTime.h"

namespace GameDirectX
{
	CZStateManagement* CZStateManagement::_spIntance = 0;

	CZStateManagement::~CZStateManagement()
	{
		SAFE_DELETE(_pCurrentState);
		SAFE_DELETE(_pNextState);
	}

	void CZStateManagement::Update(bool isPause)
	{
		// check if need switch state
		if (_pCurrentState != _pNextState)
		{
			if (_pCurrentState)
			{
				_pCurrentState->Exit();
				delete _pCurrentState;
			}
			if (_pNextState)
			{
				_pNextState->Init();
			}
			_pCurrentState = _pNextState;
			_dDelay = 0.0f;
		}

		//update state
		if (_pCurrentState)
		{
			if (!isPause)
			{
				_dDelay += CZGameTime::GetInstance()->getInterval();
				while (_dDelay >= MS_PER_UPDATE)
				{
					Log("FPS: %f", 1.0f / _dDelay); //Tinh FPS
					_pCurrentState->Update();
					_dDelay -= MS_PER_UPDATE;
				}
			}

			_pCurrentState->Render();
		}
	}

	void CZStateManagement::SwitchState(CZState* nextState)
	{
		_pNextState = nextState;
	}
}