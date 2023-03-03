#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include <Ice.h>

extern Ice::Application *Ice::CreateApplication();

int main(int argc, char **argv)
{
	Ice::Log::Init();

	ICE_CORE_INFO("Welcome to Ice Engine");

	auto app = Ice::CreateApplication();
	app->run();
	delete app;
}

#endif