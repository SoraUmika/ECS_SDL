#include "InputSystem.h"

InputSystem::InputSystem()
{
	
}

void InputSystem::Process_General_Event(SDL_Event& event)
{

}

void InputSystem::Process_Key_Event(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		printf("DOWN\n");
	}
}


bool InputSystem::Get_Key_State(SDL_Scancode scancode)
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	return currentKeyStates[scancode];
}

void InputSystem::Process_Mouse_Event(SDL_Event& event)
{
	
}

