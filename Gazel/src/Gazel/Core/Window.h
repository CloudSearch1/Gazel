#pragma once
#include"gzpch.h"

#include"Gazel/Core/Base.h"
#include"Gazel/Events/Event.h"

namespace Gazel {
	
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;
	
		WindowProps(
			const std::string& title = "Gazel Engine",
			uint32_t width = 1280,
			uint32_t height = 720
		):Title(title),Width(width),Height(height) {}

	};

	class GAZEL_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {};
		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync()const = 0;

		virtual void* GetNativeWindow() const = 0;

    static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}
