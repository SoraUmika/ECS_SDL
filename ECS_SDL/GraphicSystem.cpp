#include "GraphicSystem.h"
#include "Engine.h"
GraphicSystem::GraphicSystem()
{
	g_Renderer = Core::Get_Renderer();
}

GraphicSystem::~GraphicSystem()
{

}

void GraphicSystem::Draw_Color(SDL_Color color)
{
	SDL_SetRenderDrawColor(g_Renderer, color.r, color.g, color.b, color.a);
}

void GraphicSystem::Draw_Rect(SDL_Rect rect)
{
	SDL_RenderDrawRect(g_Renderer, &rect);
}

void GraphicSystem::Draw_Line(SDL_Point pt1, SDL_Point pt2)
{
	SDL_RenderDrawLine(g_Renderer, pt1.x, pt1.y, pt2.x, pt2.y);
}

void GraphicSystem::Draw_Texture(int x, int y, TextureComps::TextureData* textureData,
	SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, textureData->PixelDimension.x, 
		textureData->PixelDimension.y };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(g_Renderer, textureData->Texture, 
		clip, &renderQuad, angle, center, flip);
}

void GraphicSystem::Draw_Texture(GameObject textureID)
{
	auto& components = g_Engine->Get_ComponentManager();
	auto& position = components.Positions.at(textureID);
	auto& streamTexture = components.TextStreamTextures.at(textureID);
	this->Draw_Texture(position.x, position.y, &streamTexture.TextureData);
}

void GraphicSystem::Draw_Scene(GameObject sceneID)
{
	
}

void GraphicSystem::Draw_Sprite(int x, int y, TextureComps::TextureData* textureData, int index)
{	

}

void GraphicSystem::Load_Text_Texutre(TextureComps::TextureData& textureData,
	const char* text, SDL_Color color, TTF_Font* font)
{
	if (textureData.Texture != NULL)
	{
		SDL_DestroyTexture(textureData.Texture);
	}
	if (font == nullptr)
	{
		font = Core::Get_DefaultFont();
	}
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	if (textSurface == NULL)
	{
		printf("Text Surface Loaded Error! TTF_ERROR: %s\n", TTF_GetError());
	}
	else
	{
		textureData.PixelDimension.x = textSurface->w;
		textureData.PixelDimension.y = textSurface->h;
		textureData.Texture = SDL_CreateTextureFromSurface(g_Renderer, textSurface);
		if (textureData.Texture == NULL)
		{
			printf("Text Texture Loaded Error! SDL_ERROR: %s\n", SDL_GetError());
		}
	}
	SDL_FreeSurface(textSurface);
}

void GraphicSystem::Draw()
{

}