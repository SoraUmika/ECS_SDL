#ifndef UTILITIES_H
#define UTILITIES_H
#include "Core.h"
#include <assert.h>
namespace TimeUtil
{
	class TimeRepeater
	{
	public:
		TimeRepeater(Uint32 interval = 1000);
		bool Get_Signal();
		void Set_SignalInterval(Uint32 interval);
		void Reset();
	private:
		Uint32 m_PreviousTime;
		Uint32 m_Interval;
	};
}

namespace TextureUtil
{
	SDL_Texture* Texture_From_Image(const char* filepath, SDL_Point& pixelDimension);
}

#endif // !UTILITIES_H
