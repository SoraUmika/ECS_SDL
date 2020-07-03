#ifndef ENTITY_H
#define ENTITY_H
#include "Core.h"
#include "GameObject.h"

class Entity: public GameObject
{

	public:
		Entity();
		Entity(SDL_Rect rect);
		virtual ~Entity();

		unsigned int Get_ID();
		virtual void Update();
		virtual void Draw(int x ,int y);

	private:	
		unsigned int m_ID;
		static unsigned int g_EntityCount;
};


#endif // !ENTITY_H


