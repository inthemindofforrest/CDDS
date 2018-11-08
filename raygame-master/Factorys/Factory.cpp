//Factory.cpp
#include "Factory.h"

Factory::Factory()
{

}
Factory::Factory(Factory const&)
{

}
void Factory::operator=(Factory const&)
{

}


IBox* Factory::Create(std::string type)
{
	if (type == "Red")
		return new RedBox();

	if (type == "Blue")
		return new BlueBox();


	return NULL;
}

Factory & Factory::GetInstance()
{
	static Factory Instance;
	return Instance;
}