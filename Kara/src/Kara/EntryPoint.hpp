#pragma once

#ifdef KARA_PLATFORM_WINDOWS

extern Kara::Application* Kara::CreateApplication();

int main(int argc, char** argv) {
	Kara::CreateApplication()->Run();
}
#endif