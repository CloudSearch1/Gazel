#include "ParticleSystem.h"

#include "Random.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>
#include "particleEffects.h"

ParticleEffects::ParticleEffects(uint32_t maxParticles)
  :m_PoolIndex(maxParticles-1)
{
  m_ParticlePool.resize(maxParticles);
}

void ParticleEffects::OnUpdate(Gazel::Timestep ts)
{
  for (auto& particle : m_ParticlePool)
  {
    if (!particle.Active)
      continue;

    if (particle.LifeRemaining <= 0.0f)
    {
      particle.Active = false;
      continue;
    }

    particle.LifeRemaining -= ts;
    particle.Position += particle.Velocity * (float)ts;
    particle.Rotation += 0.01f * ts;
  }
}

void ParticleEffects::OnRender(Gazel::OrthographicCamera& camera)
{
  Gazel::Renderer2D::BeginScene(camera);
  for (auto& particle : m_ParticlePool)
  {
    if (!particle.Active)
      continue;

    float life = particle.LifeRemaining / particle.LifeTime;
    glm::vec4 color = glm::lerp(particle.ColorEnd, particle.ColorBegin, life);
    //color.a = color.a * life;

    float size = glm::lerp(particle.SizeEnd, particle.SizeBegin, life);
    glm::vec3 position = { particle.Position.x,particle.Position.y,0.2f };
    Gazel::Renderer2D::DrawRotatedQuad(particle.Position, { size, size }, particle.Rotation, color);
  }
  Gazel::Renderer2D::EndScene();
}

void ParticleEffects::Emit(const ParticleEffectsProps& particleEffectsProps)
{
  Particle& particle = m_ParticlePool[m_PoolIndex];
  particle.Active = true;
  particle.Position = particleEffectsProps.Position;
  particle.Rotation = Random::Float() * 2.0f * glm::pi<float>();

  // Velocity
  particle.Velocity = particleEffectsProps.Velocity;
  particle.Velocity.x += particleEffectsProps.VelocityVariation.x * (Random::Float() - 0.5f);
  particle.Velocity.y += particleEffectsProps.VelocityVariation.y * (Random::Float() - 0.5f);

  // Color
  particle.ColorBegin = particleEffectsProps.ColorBegin;
  particle.ColorEnd = particleEffectsProps.ColorEnd;

  // Size
  particle.SizeBegin = particleEffectsProps.SizeBegin + particleEffectsProps.SizeVariation * (Random::Float() - 0.5f);
  particle.SizeEnd = particleEffectsProps.SizeEnd;

  // Life
  particle.LifeTime = particleEffectsProps.LifeTime;
  particle.LifeRemaining = particleEffectsProps.LifeTime;

  m_PoolIndex = --m_PoolIndex % m_ParticlePool.size();
}
