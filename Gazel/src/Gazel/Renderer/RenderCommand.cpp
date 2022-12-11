#include "gzpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Gazel {

  Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
