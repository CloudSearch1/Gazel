#include "gzpch.h"
#include "Gazel/Core/Window.h"

#ifdef HZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Gazel
{
  Scope<Window> Window::Create(const WindowProps& props)
  {
#ifdef HZ_PLATFORM_WINDOWS
    return CreateScope<WindowsWindow>(props);
#else
    GZ_CORE_ASSERT(false, "Unknown platform!");
    return nullptr;
#endif
  }

}
