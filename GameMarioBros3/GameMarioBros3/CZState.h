#pragma once

namespace GameDirectX
{
	class CZState
	{
	public:
		CZState() {}
		virtual ~CZState() {}
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Exit() = 0;
	};
}