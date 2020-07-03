#include "WorldSystem.h"
#include "Engine.h"

WorldSystem::WorldSystem()
{
}

WorldSystem::~WorldSystem()
{

}

void WorldSystem::Init_GameObjects()
{
	m_Player = g_Engine->Get_ObjectManager().Create_GameObject();
	auto compMang = g_Engine->Get_ComponentManager();
	compMang.Positions.Add(m_Player) = { 50, 50 };
	compMang.Velocties.Add(m_Player) = { 1, 1 };
	compMang.RigidBodies.Add(m_Player) = { 50, 50, 50, 50 };

	m_Current_Scene = g_Engine->Get_ObjectManager().Create_GameObject();
	compMang.Scenes.Add(m_Current_Scene);
}

void WorldSystem::Add_Entity(ObjectType::Entity entity, SceneComps::Scene& scene)
{

}
void WorldSystem::Remove_Entity(ObjectType::Entity entity, SceneComps::Scene& scene)
{

}
void WorldSystem::Update()
{

}

void WorldSystem::Draw()
{

}

