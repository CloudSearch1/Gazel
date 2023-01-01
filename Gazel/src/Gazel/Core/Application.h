#pragma once

#include "Gazel/Core/Base.h"

#include "Gazel/Core/Window.h"
#include "Gazel/Core/LayerStack.h"
#include "Gazel/Events/Event.h"
#include "Gazel/Events/ApplicationEvent.h"

#include "Gazel/Core/Timestep.h"

#include "Gazel/ImGui/ImGuiLayer.h"

namespace Gazel {

  class Application
  {
  public:
    Application(const std::string& name = "Gazel App");
    virtual ~Application();

    void Run();

    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);

    inline Window& GetWindow() { return *m_Window; }

    void Close();
    inline static Application& Get() { return *s_Instance; }
  private:
    bool OnWindowClose(WindowCloseEvent& e);
    bool OnWindowResize(WindowResizeEvent& e);
  private:
    std::unique_ptr<Window> m_Window;
    ImGuiLayer* m_ImGuiLayer;
    bool m_Running = true;
    bool m_Minimized = false;
    LayerStack m_LayerStack;
    float m_LastFrameTime = 0.0f;
  private:
    static Application* s_Instance;
  };

  // To be defined in CLIENT
  Application* CreateApplication();

}
