#include "CZGameTime.h"

namespace GameDirectX
{
	CZGameTime* CZGameTime::_spIntance = 0;

	CZGameTime* CZGameTime::GetInstance()
	{
		if (!_spIntance)
		{
			_spIntance = new CZGameTime();
		}
		return _spIntance;
	}

	GameDirectX::CZGameTime::CZGameTime()
	{
		QueryPerformanceFrequency(&_liFreq);
		QueryPerformanceCounter(&_liLast);
		_fInterval = 0;
	}

	GameDirectX::CZGameTime::~CZGameTime()
	{
	}

	double GameDirectX::CZGameTime::getInterval()
	{
		return _fInterval;
	}

	void GameDirectX::CZGameTime::Update()
	{
		QueryPerformanceCounter(&_liNow);
		_fInterval = (double)(_liNow.QuadPart - _liLast.QuadPart) / (double)_liFreq.QuadPart;
		_liLast.QuadPart = _liNow.QuadPart;
	}

}