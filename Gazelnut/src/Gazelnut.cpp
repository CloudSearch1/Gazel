#include <Gazel.h>
#include <Gazel/Core/EntryPoint.h>


#include "EditorLayer.h"

namespace Gazel
{

  class Gazelnut : public Application
  {
  public:
    Gazelnut()
      :Application("Gazelnut")
    {
      PushLayer(new EditorLayer());
    }

    ~Gazelnut()
    {
    }
  };

  Application* CreateApplication()
  {
    return new Gazelnut();
  }
}
