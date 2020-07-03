#ifndef CORE_PRIMITIVES_H
#define CORE_PRIMITIVES_H
#include <SDL.h>

namespace Color
{
	extern SDL_Color RED;
	extern SDL_Color GREEN;
	extern SDL_Color BLUE;
	extern SDL_Color YELLOW;
	extern SDL_Color PURPLE;
	extern SDL_Color ORANGE;
	extern SDL_Color WHITE;
	extern SDL_Color BLACK;
};

namespace Vector
{
	template <class T>
	struct Vect2D
	{
		T x; T y;
	};
};

struct Transform
{
	SDL_Rect rect = { 0, 0, 0, 0 };
	Vector::Vect2D<float> scale = { 1.0, 1.0 };
};
#endif // !CORE_PRIMITIVES_H


