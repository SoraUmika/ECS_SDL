#ifndef GRAPHICSYSTEM_H
#define GRAPHICSYSTEM_H
#include "System.h"
#include "Component.h"
class GraphicSystem: public System
{
public:
	GraphicSystem();
	~GraphicSystem();

	void Draw_Color(SDL_Color color);
	void Draw_Rect(SDL_Rect rect);
	void Draw_Line(SDL_Point pt1, SDL_Point pt2);

	void Draw_Texture(int x, int y, TextureComps::TextureData* textureData, SDL_Rect* clip=NULL, double angle=0.0,
		SDL_Point* center=NULL, SDL_RendererFlip flip=SDL_FLIP_NONE);

	//Looks for the Position and TextureData Component then draw the texture
	void Draw_Texture(GameObject textureID);
	void Draw_Scene(GameObject sceneID);
	//uniform spritesheet
	void Draw_Sprite(int x, int y, TextureComps::TextureData* textureData, int index);

	void Load_Text_Texutre(TextureComps::TextureData& textureData,
		const char* text, SDL_Color color = {0, 50, 255, 255}, TTF_Font* font = nullptr);
	void Draw();
	
private:
	SDL_Renderer* g_Renderer;
};


#endif // !

