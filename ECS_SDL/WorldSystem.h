#ifndef WorldSystem_H
#define WorldSystem_H

#include "System.h"
#include "Component.h"
#include "GameObject.h"

class WorldSystem: public System
{
public:
	WorldSystem();
	~WorldSystem();

	void Init_GameObjects();
	void Add_Entity(ObjectType::Entity entity, SceneComps::Scene& scene);
	void Remove_Entity(ObjectType::Entity entity, SceneComps::Scene& scene);

	void Update();
	void Draw();
private:
	GameObject m_Player;
	GameObject m_Current_Scene;

};

#endif // !WorldSystem_H


