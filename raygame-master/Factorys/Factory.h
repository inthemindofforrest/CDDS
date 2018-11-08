//Factory.h
#pragma once
#include <iostream>
#include "IBox.h"
#include "RedBox.h"
#include "BlueBox.h"
#include "IFactory.h"

class Factory : public IFactory
{
private:
	Factory();
	Factory(Factory const&);  // prevents external use
	void operator=(Factory const&); // prevents external use

public:
	IBox * Create(std::string type);
	static Factory& GetInstance();
};