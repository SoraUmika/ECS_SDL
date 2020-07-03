#ifndef GameObjectMANAGER
#define GameObjectMANAGER
#include "GameObject.h"
#include <unordered_set>
#include <assert.h>
class GameObjectManager
{
public:
	GameObject Create_GameObject()
	{
		static GameObject next = 0;
		//check to see if the next + 1 exist in list,
		//if not then given new GameObject id of value next + 1
		if (m_GameObject_List.find(++next) == m_GameObject_List.end())
		{
			m_GameObject_List.insert(next);
			return next;
		}
		else
		{
			return Create_GameObject();
		}
	}
	//give GameObject a specific id
	bool Create_GameObject(GameObject GameObject)
	{
		//check to see if it exist, if it does then report error
		assert(m_GameObject_List.find(GameObject) == m_GameObject_List.end());
		
		m_GameObject_List.insert(GameObject);
		return true;
	}
	
private:
	std::unordered_set<GameObject> m_GameObject_List;
};

#endif // !GameObjectMANAGER


