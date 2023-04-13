#pragma once
#include "MyBase.h"
#include "MyConfig.h"

class MyDerived : public MyBase
{
public:
	int SubSomething(int initVal) {
		return initVal - 1;
	}
	int AddSomething(int initVal) override;

public:
	Config conf;
};

