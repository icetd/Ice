#include <Ice.h>

class Sandbox : public Ice::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Ice::Application *Ice::CreateApplication()
{
	return new Sandbox();
}
