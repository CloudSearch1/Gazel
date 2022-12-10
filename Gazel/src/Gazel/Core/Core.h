#pragma once
#include<memory>

//#define GAZEL_API __declspec(dllexport)
#ifdef GZ_PLATFORM_WINDOWS
//#if GZ_DYNAMIC_LINK
	#ifdef GZ_BUILD_DLL
		#define GAZEL_API __declspec(dllexport)
	#else
		#define GAZEL_API __declspec(dllimport)
	#endif
#else
	#define GAZEL_API
error Gazel Only can be used in Windows!
#endif

#ifdef GZ_ENABLE_ASSERTS
	#define GZ_ASSERT(x, ...){if(!x){GZ_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
	#define GZ_CORE_ASSERT(x, ...){if(!x){GZ_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
	#define GZ_ASSERT(x, ...)
	#define GZ_CORE_ASSERT(x, ...)
#endif // GZ_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define GZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Gazel
{
  template<typename T>
  using Scope = std::unique_ptr<T>;
  template<typename T, typename ... Args>
  constexpr Scope<T> CreateScope(Args&& ... args)
  {
    return std::make_unique<T>(std::forward<Args>(args)...);
  }

  template<typename T>
  using Ref = std::shared_ptr<T>;

  template<typename T, typename ... Args>
  constexpr Ref<T> CreateRef(Args&& ... args)
  {
    return std::make_shared<T>(std::forward<Args>(args)...);
  }
}
