#pragma once

#include "Gazel.h"

class Sandbox2D : public Gazel::Layer
{
public:
  Sandbox2D();
  virtual ~Sandbox2D() = default;

  virtual void OnAttach() override;
  virtual void OnDetach() override;

  void OnUpdate(Gazel::Timestep ts) override;
  virtual void OnImGuiRender() override;
  void OnEvent(Gazel::Event& e) override;
private:
  Gazel::OrthographicCameraController m_CameraController;

  // Temp
  Gazel::Ref<Gazel::VertexArray> m_SquareVA;
  Gazel::Ref<Gazel::Shader> m_FlatColorShader;

  Gazel::Ref<Gazel::Texture2D> m_CheckerboardTexture;

  glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
