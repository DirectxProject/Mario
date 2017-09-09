#include "Example.h"
#include "CZStateManagement.h"
#include <iostream>
#include "StateExample.h"
#include "CZMacro.h"

bool Example::Init()
{
	std::cout << "Init\n";
	//Create Window
	this->_pWindow = new CZWindow(640, 480);
	this->_pWindow->CreateWindowGame("Mario");

	if (this->_pWindow->getHWND() == NULL)
		return false;
	//Create Directx

	//Create Keyboard

	//Create Resouce

	CZStateManagement::GetInstance()->SwitchState(new StateExample());
	return true;
}

void Example::Destroy()
{
	std::cout << "Destroy\n";

	//Destroy Resource

	//Destroy Keyboard

	//Destroy Directx

	//Destroy Window
	this->_pWindow->DestroyWindowGame();
	SAFE_DELETE(_pWindow);
}
