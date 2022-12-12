#pragma once

#include <Gazel.h>

struct ParticleEffectsProps
{
  glm::vec2 Position;
  glm::vec2 Velocity, VelocityVariation;
  glm::vec4 ColorBegin, ColorEnd;
  float SizeBegin, SizeEnd, SizeVariation;
  float LifeTime = 1.0f;
};

class ParticleEffects
{
public:
  ParticleEffects(uint32_t maxParticles = 100000);

  void OnUpdate(Gazel::Timestep ts);
  void OnRender(Gazel::OrthographicCamera& camera);

  void Emit(const ParticleEffectsProps& particleEffectsProps);
private:
  struct Particle
  {
    glm::vec2 Position;
    glm::vec2 Velocity;
    glm::vec4 ColorBegin, ColorEnd;
    float Rotation = 0.0f;
    float SizeBegin, SizeEnd;

    float LifeTime = 1.0f;
    float LifeRemaining = 0.0f;

    bool Active = false;
  };
  std::vector<Particle> m_ParticlePool;
  uint32_t m_PoolIndex = 0;
};
