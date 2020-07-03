#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H
#include "System.h"
#include "Component.h"
#include "GameObject.h"
class PhysicSystem: public System
{
public:
	PhysicSystem();
	~PhysicSystem();
	bool Is_Collision(ObjectType::Entity entity);
	void Update();
private:

};


#endif // !PHYSICSYSTEM_H

