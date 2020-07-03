#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <unordered_map>
#include <array>
#include <assert.h>
#include "GameObject.h"
#include "Component.h"

template <typename ComponentType>
class ComponentManager
{
public:
	ComponentManager()
	{
		m_GameObjects.reserve(1);
		m_Components.reserve(1);
	}
	~ComponentManager(){}
	ComponentType& Add(GameObject gameObject)
	{
		assert(gameObject != INVALID_GAMEOBJECT);

		//One Component	type per game
		assert(m_Look_up.find(gameObject) == m_Look_up.end());
		
		assert(m_Look_up.size() == m_Components.size());
		assert(m_GameObjects.size() == m_Components.size());

		m_Look_up[gameObject] = m_Components.size();

		m_Components.push_back(ComponentType());

		m_GameObjects.push_back(gameObject);

		return m_Components.back();
	}
	void Remove(GameObject gameObject)
	{
		auto it = m_Look_up.find(gameObject);
		if (it != m_Look_up.end())
		{
			const size_t index = it->second;
			const GameObject = m_GameObjects[index];

			if (index < m_Components.size() - 1)
			{
				m_Components[index] = std::move(m_Components.back());
				m_GameObjects[index] = m_GameObjects.back();

				m_Look_up[m_GameObjects[index]] = index;
			}

			m_Components.pop_back();
			m_GameObjects.pop_back();
			m_Look_up.erase(gameObject);
		}
		else
		{
			printf("GameObject doesn't exist anyway\n");
		}
	}

	size_t Get_Count() const
	{
		return m_Components.size();
	}

	ComponentType& operator[](size_t index) const 
	{
		return m_Components[index];
	}
	ComponentType& at(size_t index) const
	{
		return m_Components.at(index);
	}
	ComponentType& operator[](GameObject gameObject)
	{
		auto it = m_Look_up.find(gameObject);
		if (it != m_Look_up.end())
		{
			return m_Components[it->second];
		}
	}
	ComponentType& at(GameObject gameObject)
	{
		auto it = m_Look_up.find(gameObject);
		if (it != m_Look_up.end())
		{
			return m_Components.at(it->second);
		}
	}

	bool Contains(GameObject gameObject) const
	{
		return m_Look_up.find(gameObject) != m_Look_up.end();
	}
	GameObject Get_GameObject(size_t index) const
	{
		return m_GameObjects[index];
	}
	size_t Get_Index(GameObject gameObject) const 
	{
		return m_Look_up.at(gameObject);
	}

private:
	static const GameObject INVALID_GAMEOBJECT= 0;

	std::unordered_map<GameObject, size_t> m_Look_up;
	std::vector<GameObject> m_GameObjects;
	std::vector<ComponentType> m_Components;
};


struct ComponentManagers
{
	ComponentManager<TransformComps::Position> Positions;
	ComponentManager<TransformComps::Velocity> Velocties;
	ComponentManager<TransformComps::RigidBody> RigidBodies;

	ComponentManager<TextureComps::TextureData> TextureDatas;
	ComponentManager<TextureComps::TextStreamTexture> TextStreamTextures;

	ComponentManager<SceneComps::Scene> Scenes;

};
#endif // !COMPONENTMANAGER_H




