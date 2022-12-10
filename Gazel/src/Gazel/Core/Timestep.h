#pragma once


namespace Gazel
{
  class Timestep
  {
  public:
    Timestep(float time)
      :m_Time(time)
    {
    }

    operator float() const { return m_Time; }

    float GetSeconds() const { return m_Time; }
    float GetMillSeconds() const { return m_Time * 1000.0f; }
  private:
    float m_Time;
  };
}
