#include <Gazel.h>
#include <Gazel/Core/EntryPoint.h>

#include "GameLayer.h"
#include "ExampleLayer.h"
#include "SandBox2D.h"

class Sandbox : public Gazel::Application
{
public:
  Sandbox()
  {
    PushLayer(new GameLayer());
    //PushLayer(new Sandbox2D());
    //PushLayer(new ExampleLayer());
  }

  ~Sandbox()
  {
  }
};

Gazel::Application* Gazel::CreateApplication()
{
  return new Sandbox();
}
