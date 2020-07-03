#include "Core.h"

namespace Core
{
	SDL_Window* g_Window = NULL;
	SDL_Renderer* g_Renderer = NULL;
	TTF_Font* g_Font = NULL;

	SDL_Point g_Window_Size = { 0, 0 };
	SDL_Point g_Resolution = { 0, 0 };

	bool Init_Window(const char* program_title, int window_Size_x, int window_Size_y)
	{
		bool success = true;
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			g_Window_Size.x = window_Size_x;
			g_Window_Size.y = window_Size_y;
			g_Window = SDL_CreateWindow(program_title, SDL_WINDOWPOS_CENTERED, 
				SDL_WINDOWPOS_CENTERED, window_Size_x, window_Size_y, SDL_WINDOW_SHOWN);
			if (g_Window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
		}
		return success;
	}

	bool Init_Renderer(int logical_Res_x, int logical_Res_y)
	{
		bool success = true;
		g_Renderer = SDL_CreateRenderer
		(
			g_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
		if (g_Renderer == NULL)
		{
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			g_Resolution = { logical_Res_x, logical_Res_y };
			SDL_RenderSetLogicalSize(g_Renderer, logical_Res_x, logical_Res_y);	
			SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf
				(
					"SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError()
				);
				success = false;
			}

			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				success = false;
			}
			else
			{
				g_Font = TTF_OpenFont("Content/Fonts/default_font.ttf", 20);
				if (g_Font == NULL)
				{
					printf("Failed to load default font! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
				int index;
				for (unsigned char currentChar = 32; currentChar < 255; currentChar++)
				{
					if (currentChar == 127)
					{
						currentChar = 159;
						continue;
					}
					index = TTF_GlyphIsProvided(g_Font, currentChar);
					if (!index)
						printf("There is no '%c' in the loaded font! ASCII: %i\n", 
							currentChar, currentChar);
				}

			}
		}
		return success;
	}

	bool Free_All()
	{
		SDL_DestroyWindow(g_Window);
		SDL_DestroyRenderer(g_Renderer);
		TTF_CloseFont(g_Font);

		g_Font = NULL;
		g_Window = NULL;
		g_Renderer = NULL;

		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		return true;
	}

	SDL_Window* Get_Window()
	{
		return g_Window;
	}

	SDL_Renderer* Get_Renderer()
	{
		return g_Renderer;
	}
	
	TTF_Font* Get_DefaultFont()
	{
		return g_Font;
	}
	SDL_Point Get_Window_Size()
	{
		return g_Window_Size;
	}

	SDL_Point Get_Resolution()
	{
		return g_Resolution;
	}

}