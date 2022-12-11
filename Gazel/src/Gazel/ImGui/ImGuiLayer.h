#pragma once

#include "Gazel/Core/Layer.h"

#include "Gazel/Events/ApplicationEvent.h"
#include "Gazel/Events/KeyEvent.h"
#include "Gazel/Events/MouseEvent.h"

namespace Gazel {

  class ImGuiLayer : public Layer
  {
  public:
    ImGuiLayer();
    ~ImGuiLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void Begin();
    void End();
  private:
    float m_Time = 0.0f;
  };

}
