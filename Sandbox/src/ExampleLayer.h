#pragma once

#include "Gazel.h"

class ExampleLayer : public Gazel::Layer
{
public:
  ExampleLayer();
  virtual ~ExampleLayer() = default;

  virtual void OnAttach() override;
  virtual void OnDetach() override;

  void OnUpdate(Gazel::Timestep ts) override;
  virtual void OnImGuiRender() override;
  void OnEvent(Gazel::Event& e) override;
private:
  Gazel::ShaderLibrary m_ShaderLibrary;
  Gazel::Ref<Gazel::Shader> m_Shader;
  Gazel::Ref<Gazel::VertexArray> m_VertexArray;

  Gazel::Ref<Gazel::Shader> m_FlatColorShader;
  Gazel::Ref<Gazel::VertexArray> m_SquareVA;

  Gazel::Ref<Gazel::Texture2D> m_Texture, m_ChernoLogoTexture;

  Gazel::OrthographicCameraController m_CameraController;
  glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

