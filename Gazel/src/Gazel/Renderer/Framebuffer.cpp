#include"gzpch.h"

#include"Renderer.h"
#include"Framebuffer.h"
#include"Platform/OpenGL/OpenGLFramebuffer.h"

namespace Gazel
{
  Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
  {
	  switch (Renderer::GetAPI())
	  {
		  case RendererAPI::API::None: GZ_CORE_ASSERT(false, "None is not supported!"); return nullptr;
		  case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);
	  }
	  GZ_CORE_ASSERT(false, "Unknow RendererAPI!");
	  return nullptr;
  }
}
