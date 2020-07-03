#include "Utilities.h"

namespace TimeUtil
{
	TimeRepeater::TimeRepeater(Uint32 interval)
		: m_Interval(interval), m_PreviousTime(0)
	{
	}
	bool TimeRepeater::Get_Signal()
	{
		if (SDL_GetTicks() - m_PreviousTime >= m_Interval)
		{
			m_PreviousTime = SDL_GetTicks();
			return true;
		}
		else
		{
			return false;
		}
	}
	void TimeRepeater::Set_SignalInterval(Uint32 interval)
	{
		m_Interval = interval;
	}
	void TimeRepeater::Reset()
	{
		m_PreviousTime = 0;
	}
}

namespace TextureUtil
{
	SDL_Texture* Texture_From_Image(const char* filepath, SDL_Point& pixelDimension)
	{
		SDL_Surface* tmpSurface = IMG_Load(filepath);
		pixelDimension.x = tmpSurface->w;
		pixelDimension.y = tmpSurface->h;

		SDL_Texture* texture = NULL;

		assert(tmpSurface != NULL);

		texture = SDL_CreateTextureFromSurface(Core::Get_Renderer(), tmpSurface);

		assert(texture != NULL);

		SDL_FreeSurface(tmpSurface);

		return texture;
	}
}