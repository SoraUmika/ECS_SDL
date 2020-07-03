#ifndef CORE_H
#ifndef CORE_H
#define CORE_H
#endif // !CORE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
namespace Core
{
	bool Init_Window(const char* program_title, int window_Size_x, int window_Size_y);
	bool Init_Renderer(int logical_Res_x, int logical_Res_y);
	bool Free_All();

	SDL_Window* Get_Window();
	SDL_Renderer* Get_Renderer();
	TTF_Font* Get_DefaultFont();

	SDL_Point Get_Window_Size();
	SDL_Point Get_Resolution();



}


#endif // !CORE_H

