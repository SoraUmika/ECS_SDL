#ifndef ENGINE_H
#define ENGINE_H
#include "Core.h"
#include <chrono>
#include "Utilities.h"

#include "PhysicSystem.h"
#include "GraphicSystem.h"
#include "InputSystem.h"
#include "AISystem.h"
#include "TimeSystem.h"
#include "WorldSystem.h"

#include "ComponentManager.h"
#include "GameObjectManager.h"

struct Systems
{
	PhysicSystem PhysicSystem;
	GraphicSystem GraphicSystem;
	InputSystem InputSystem;
	AISystem AISystem;
	TimeSystem TimeSystem;
	WorldSystem WorldSystem;
};

class Engine
{
public:
	Engine();
	~Engine();

	void Init_Systems();
	void Init_Engine_Object();

	PhysicSystem& Get_PhysicSystem();
	GraphicSystem& Get_GraphicSystem();
	InputSystem& Get_InputSystem();
	AISystem& Get_AISystem();
	TimeSystem& Get_TimeSystem();
	WorldSystem& Get_WorldSystem();

	GameObjectManager& Get_ObjectManager();
	ComponentManagers& Get_ComponentManager();
	void Run();
private:
	void Update();
	void Render();
	bool m_Quit;
	SDL_Event m_Event;

	//Engine Loop Info
	unsigned int Updates_Per_Sec = 0;
	unsigned int Frames_Per_Sec = 0;
	GameObject m_Fps_Ups_Texture;

	//Engine Systems
	Systems m_Systems;

	//Engnie Component Manager
	ComponentManagers m_ComponentManagers;

	//GameObject Manager;
	GameObjectManager m_Object_Managers;
};

#endif // !GAME_H


