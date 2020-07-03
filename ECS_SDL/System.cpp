#include "System.h"

Engine* System::g_Engine = nullptr;
Systems* System::g_Systems = nullptr;

size_t System::g_UpdateCount = 0;

System::System()
{
}

System::~System()
{

}

void System::Set_Engine(Engine* engine)
{
	g_Engine = engine;
}

void System::Set_Systems(Systems* systems)
{
	g_Systems = systems;
}

void System::Increment_Update()
{
	g_UpdateCount++;
}

size_t System::Get_Update_Count()
{
	return g_UpdateCount;
}