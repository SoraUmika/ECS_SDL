#ifndef COMPONENT_H
#define COMPONENT_H
#include "Core.h"
#include <vector>
#include "GameObject.h"
#include <unordered_set>
#include <unordered_map>
typedef SDL_Point Vect2D;

namespace TransformComps
{
	struct Position
	{
		int x = 0;
		int y = 0;
	};

	struct Velocity
	{
		int x = 0;
		int y = 0;
	};

	struct RigidBody
	{
		SDL_Rect Rect = { 0, 0, 0, 0 };
		bool IsRigid = true;
	};
}

//GraphicsData
namespace TextureComps
{
	struct TextureData
	{
		SDL_Texture* Texture = NULL;
		Vect2D PixelDimension = { 0, 0 };
	};

	struct TextStreamTexture
	{
		TextureData TextureData;
		char Buffer[32];
	};

	struct SpriteSheet
	{

	};
}

namespace SceneComps
{
	//Scene DATATYPE
	#define DEFAULT_TILE_COUNT 16
	#define DEFAULT_TILE_SIZE 16
	#define TILES_PER_CHUNK 8
	struct LogicCell
	{
		//Stores Entity that has a rigidBody
		std::unordered_set<ObjectType::Entity> RigidBodies;
	};

	struct LogicGrid
	{
		const static size_t T_P_S = TILES_PER_CHUNK;
		LogicGrid()
			:CellCount_x(DEFAULT_TILE_COUNT/TILES_PER_CHUNK), 
			CellCount_y(DEFAULT_TILE_COUNT/TILES_PER_CHUNK)
		{
			Cells.resize(CellCount_x * CellCount_y);
		}
		std::vector<LogicCell> Cells;
		size_t CellCount_x;
		size_t CellCount_y;
	};

	struct SceneTileData
	{
		SceneTileData()
			:TileCount_x(DEFAULT_TILE_COUNT), TileCount_y(DEFAULT_TILE_COUNT)
		{
			Data.resize(TileCount_x * TileCount_y);
		}
		std::vector<unsigned short> Data;
		size_t TileCount_x;
		size_t TileCount_y;
	};

	struct Scene
	{
		LogicGrid LogicGrid;
		SceneTileData SceneTileData;
		std::unordered_set<ObjectType::Entity> Entities;
		GameObject TileTexture_ID;
		char SceneName[20] = "MyScene";
	};
}

//input


#endif // !
