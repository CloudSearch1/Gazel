#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
  : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
  m_CheckerboardTexture = Gazel::Texture2D::Create("assets/textures/baby.png");

  //粒子特效
  m_ParticlesEffectsProps.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
  m_ParticlesEffectsProps.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 31 / 255.0f , 1.0f };
  m_ParticlesEffectsProps.SizeBegin = 0.5f, m_ParticlesEffectsProps.SizeEnd = 0.0f, m_ParticlesEffectsProps.SizeVariation = 0.3f;
  m_ParticlesEffectsProps.LifeTime = 1.0f;
  m_ParticlesEffectsProps.Velocity = { 0.0f, 0.0f };
  m_ParticlesEffectsProps.VelocityVariation = { 3.0f, 0.0f };
  m_ParticlesEffectsProps.Position = { 0.0f, 0.0f };

}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Gazel::Timestep ts)
{
  ////材质和四方形
  //{
  //  // Update
  //  m_CameraController.OnUpdate(ts);

  //  // Render
  //  Gazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
  //  Gazel::RenderCommand::Clear();

  //  Gazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
  //  Gazel::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
  //  Gazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
  //  Gazel::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f,10.0f }, glm::radians(0.0f), m_CheckerboardTexture);
  //  Gazel::Renderer2D::EndScene();
  //}
  ////粒子特效
  //{
  //  if (Gazel::Input::IsMouseButtonPressed(0))
  //  {
  //    auto [x, y] = Gazel::Input::GetMousePosition();
  //    auto width = Gazel::Application::Get().GetWindow().GetWidth();
  //    auto height = Gazel::Application::Get().GetWindow().GetHeight();

  //    auto bounds = m_CameraController.GetBounds();
  //    auto pos = m_CameraController.GetCamera().GetPosition();
  //    x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
  //    y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
  //    m_ParticlesEffectsProps.Position = { x + pos.x,y + pos.y };
  //    for (int i = 0; i < 5; i++)
  //    {
  //      m_ParticleEffects.Emit(m_ParticlesEffectsProps);
  //    }
  //   
  //  }
  //  m_ParticleEffects.OnUpdate(ts);
  //  m_ParticleEffects.OnRender(m_CameraController.GetCamera());

  //}

  {
    m_CameraController.OnUpdate(ts);
    // Render
    {
      Gazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
      Gazel::RenderCommand::Clear();
    }
    Gazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
    Gazel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
    Gazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
    Gazel::Renderer2D::EndScene();
  }
}

void Sandbox2D::OnImGuiRender()
{
  ImGui::Begin("Settings");
  ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
  ImGui::End();
}

void Sandbox2D::OnEvent(Gazel::Event& e)
{
  m_CameraController.OnEvent(e);
}
