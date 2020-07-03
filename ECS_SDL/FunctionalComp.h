#pragma once
#include "Core.h"
#include "Component.h"
class FunctionalComp
{
public:
	virtual void Update() = 0;
};

namespace InputComps
{
	class Input
	{
	public:
		virtual void Update(SDL_Event& event) = 0;
	};
	
	class Player : public Input
	{
	public:
		void Update(SDL_Event& event)
		{
			switch (event.key.keysym.scancode)
			{

			}
		}
	};
}

