#pragma once
#include"Core.h"

#include"Gazel/Events/Event.h"
#include"Gazel/Core/Window.h"
#include"Gazel/Events/ApplicationEvent.h"
#include"LayerStack.h"
//#include"Gazel/ImGui/ImGuiLayer.h"

#include"Gazel/Renderer/Shader.h"
#include <Gazel/Renderer/Buffer.h>
#include"Gazel/Renderer/VertexArray.h"
#include"Gazel/Renderer/OrthographicCamera.h"
#include"Gazel/Core/Timestep.h"

namespace Gazel {
	//__declspec(dllexport) GAZEL_API
	class GAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
  private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
    bool m_Minimized = false;
		LayerStack m_LayerStack;
		//ImGuiLayer* m_ImGuiLayer;
    float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;

	};
	Application* CreateApplication();
}

