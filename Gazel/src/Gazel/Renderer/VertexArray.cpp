#include "VertexArray.h"
#include"gzpch.h"
#include"VertexArray.h"
#include"Renderer.h"
#include"Platform/OpenGL/OpenGLVertexArray.h"

namespace Gazel
{
  std::shared_ptr<VertexArray> VertexArray::Create()
  {
    switch (Renderer::GetAPI())
    {
    case RendererAPI::API::None:    GZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
    case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
    }

    GZ_CORE_ASSERT(false, "Unknown RendererAPI!");
    return nullptr;
  }
}
