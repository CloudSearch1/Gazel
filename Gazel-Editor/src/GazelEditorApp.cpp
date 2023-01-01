#include <Gazel.h>
#include <Gazel/Core/EntryPoint.h>


#include "EditorLayer.h"

namespace Gazel
{

  class GazelEditor : public Application
  {
  public:
    GazelEditor()
    {
      PushLayer(new EditorLayer());
    }

    ~GazelEditor()
    {
    }
  };

  Application* CreateApplication()
  {
    return new GazelEditor();
  }

}
