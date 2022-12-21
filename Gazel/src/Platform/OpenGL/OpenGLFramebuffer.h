#pragma once

#include"Gazel/Renderer/Framebuffer.h"

namespace Gazel
{
  class OpenGLFramebuffer: public Framebuffer
  {
  public:
    OpenGLFramebuffer(const FramebufferSpecification& spec);
    virtual ~OpenGLFramebuffer();

    void Invalidate();

    virtual uint32_t GetColorAttachmentRendererID() const override { return m_RendererID; }

    virtual void Bind() override;
    virtual void Unbind() override;

    virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }
  private:
    uint32_t m_RendererID;
    uint32_t m_ColorAttachment, m_DepthAttachment;
    FramebufferSpecification m_Specification;
  };
}
