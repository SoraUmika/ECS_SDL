#ifndef SYSTEM_H
#define SYSTEM_H
#include "Core.h"
#include <assert.h>

class WorldSystem;
class Engine;
struct ComponentManagers;
struct Systems;

class System
{
public:
	System();
	~System();
	static size_t Get_Update_Count();
	static void Set_Engine(Engine* engine);
	static void Set_Systems(Systems* systems);
	static void Increment_Update();
protected:
	static Engine* g_Engine;
	static Systems* g_Systems;
	static size_t g_UpdateCount;
private:
}; 

#endif // !SYSTEM_H

