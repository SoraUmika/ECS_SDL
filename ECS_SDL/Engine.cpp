#include "Engine.h"

Engine::Engine()
	:m_Quit(false)
{
	SceneComps::Scene scene;
}

Engine::~Engine()
{

}

void Engine::Init_Systems()
{
	System::Set_Engine(this);
	System::Set_Systems(&m_Systems);

}

void Engine::Init_Engine_Object()
{
	m_Fps_Ups_Texture = m_Object_Managers.Create_GameObject();
	m_ComponentManagers.TextStreamTextures.Add(m_Fps_Ups_Texture);
	m_ComponentManagers.Positions.Add(m_Fps_Ups_Texture) = {5, 0};
}

PhysicSystem& Engine::Get_PhysicSystem()
{
	return m_Systems.PhysicSystem;
}

GraphicSystem& Engine::Get_GraphicSystem()
{
	return m_Systems.GraphicSystem;
}
InputSystem& Engine::Get_InputSystem()
{
	return m_Systems.InputSystem;
}

AISystem& Engine::Get_AISystem()
{
	return m_Systems.AISystem;
}

TimeSystem& Engine::Get_TimeSystem()
{
	return m_Systems.TimeSystem;
}

WorldSystem& Engine::Get_WorldSystem()
{
	return m_Systems.WorldSystem;
}

GameObjectManager& Engine::Get_ObjectManager()
{
	return m_Object_Managers;
}

ComponentManagers& Engine::Get_ComponentManager()
{
	return m_ComponentManagers;
}

void Engine::Render()
{
	SDL_Renderer* renderer_ptr = Core::Get_Renderer();
	SDL_SetRenderDrawColor(renderer_ptr, 255, 255, 255, 255);
	SDL_RenderClear(renderer_ptr);

	m_Systems.WorldSystem.Draw();
	m_Systems.GraphicSystem.Draw_Texture(m_Fps_Ups_Texture);
	SDL_RenderPresent(renderer_ptr);
}

void Engine::Update()
{
	while (SDL_PollEvent(&m_Event) != 0)
	{
		switch (m_Event.type)
		{
		case SDL_QUIT:
			m_Quit = true;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			m_Systems.InputSystem.Process_Key_Event(m_Event);
			break;
		case SDL_MOUSEMOTION:
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEWHEEL:
			m_Systems.InputSystem.Process_Mouse_Event(m_Event);
			break;

		}
	}
	m_Systems.WorldSystem.Update();
}

using namespace std::chrono;
void Engine::Run()
{
	const double MS_PER_UPDATE = 10.0;
	steady_clock::time_point Previous_Time = high_resolution_clock::now();
	steady_clock::time_point Current_Time;
	duration<double, std::milli> Elapsed_Time;
	double Lag = 0.0;
	
	auto& textTexture = m_ComponentManagers.TextStreamTextures.at(m_Fps_Ups_Texture);
	sprintf_s(textTexture.Buffer, "Fps: %i, Ups: %i", 0, 0);
	m_Systems.GraphicSystem.Load_Text_Texutre(textTexture.TextureData, textTexture.Buffer);

	TimeUtil::TimeRepeater timeRepeater;
	while (!m_Quit)
	{
		Current_Time = high_resolution_clock::now();
		Elapsed_Time = Current_Time - Previous_Time;
		Previous_Time = Current_Time;
		Lag += Elapsed_Time.count();
		while (Lag >= MS_PER_UPDATE)
		{
			Update();
			Lag -= MS_PER_UPDATE;
			++Updates_Per_Sec;
			System::Increment_Update();
		}
		if (timeRepeater.Get_Signal())
		{
			sprintf_s(textTexture.Buffer, "Fps: %i, Ups: %i", 
				Frames_Per_Sec, Updates_Per_Sec);
			m_Systems.GraphicSystem.Load_Text_Texutre(textTexture.TextureData, textTexture.Buffer);

			Updates_Per_Sec = 0;
			Frames_Per_Sec = 0;
		}
		Render();
		++Frames_Per_Sec;
	}
}