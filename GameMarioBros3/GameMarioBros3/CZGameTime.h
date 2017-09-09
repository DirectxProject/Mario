#pragma once

#include <Windows.h>

namespace GameDirectX 
{

#define MS_PER_UPDATE 1.0f / 60

	class CZGameTime 
	{
	public:
		static CZGameTime* GetInstance();

		~CZGameTime();

		double getInterval();
		void Update();

	protected:
		static CZGameTime* _spIntance;	
		CZGameTime();

	protected:
		LARGE_INTEGER _liLast;	// thoi gian ban dau
		LARGE_INTEGER _liNow;	// thoi gian hien tai
		LARGE_INTEGER _liFreq;	// 
		double _fInterval; //Thoi gian game run
	};

}