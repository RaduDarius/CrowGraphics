#pragma once

#ifdef KARA_PLATFORM_WINDOWS
namespace Kara {
extern Application *CreateApplication();
}

int main(int argc, char **argv) { Kara::CreateApplication()->Run(); }
#endif
