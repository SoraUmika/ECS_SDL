#pragma once

#include "System.h"
#include "GameObject.h"
#include "Component.h"
class InputSystem: public System
{
public:
	InputSystem();
	void Process_General_Event(SDL_Event& event);
	void Process_Key_Event(SDL_Event& event);
	void Process_Mouse_Event(SDL_Event& event);

	bool Get_Key_State(SDL_Scancode scancode);
private:

	
};

