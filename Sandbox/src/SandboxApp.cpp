#include <Kara.hpp>

class Sandbox : public Kara::Application {};

namespace Kara {
	Application* CreateApplication() {
		return new Sandbox();
	}
}