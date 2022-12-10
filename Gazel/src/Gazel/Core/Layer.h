#pragma once

#include"Gazel/Core/Core.h"
#include"Gazel/Events/Event.h"
#include"Gazel/Core/Timestep.h"

namespace Gazel{

	class GAZEL_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event& event) {}
		virtual void OnImguiRender() {};

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
