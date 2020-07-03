#include "ComponentUtilities.h"

void Util_Texture_Load(TextureComps::TextureData& textureData, const char* filepath)
{
	//check to see if texture is intialized
	if (textureData.Texture != NULL)
	{
		printf("Texture already initialized, path: %s\n", filepath);
		assert(0);
	}
	else
	{
		//load to a tmp surface and assign pixel width and height
		SDL_Surface* tmpSurface = IMG_Load(filepath);

		//check to see if loaded correctly
		if (tmpSurface == NULL)
		{
			printf("Surface Load Error: %s\n", SDL_GetError());
			assert(0);
		}
		else
		{
			textureData.PixelDimension.x = tmpSurface->w;
			textureData.PixelDimension.y = tmpSurface->h;

			//create the texture from surface
			textureData.Texture = SDL_CreateTextureFromSurface(Core::Get_Renderer(), tmpSurface);

			//check to see if the texture was created sucessfully
			if (textureData.Texture == NULL)
			{
				printf("Texture Load Error: %s\n", SDL_GetError());
				assert(0);
			}
			//free the surface
			SDL_FreeSurface(tmpSurface);
		}
	}

}

void Util_Scene_Load(SceneComps::Scene& scene, const char* filepath)
{
	size_t TileCount_x = DEFAULT_TILE_COUNT;
	size_t TileCount_y = DEFAULT_TILE_COUNT;
	if (filepath != nullptr)
	{
		//do something
	}

	//Initialize Tiledata
	auto& TileData = scene.SceneTileData;
	TileData.TileCount_x = TileCount_x;
	TileData.TileCount_y = TileCount_y;
	TileData.Data.resize(TileCount_x * TileCount_y);

	auto& LogicGrid = scene.LogicGrid;
	LogicGrid.CellCount_x = TileCount_x / TILES_PER_CHUNK;
	LogicGrid.CellCount_y = TileCount_y / TILES_PER_CHUNK;

	if (TileCount_x % TILES_PER_CHUNK > 0) ++LogicGrid.CellCount_x;
	if (TileCount_y % TILES_PER_CHUNK > 0) ++LogicGrid.CellCount_y;

	LogicGrid.Cells.resize(LogicGrid.CellCount_x * LogicGrid.CellCount_y);
}