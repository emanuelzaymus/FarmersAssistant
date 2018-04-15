#pragma once

#include <string>

#include "PopulationInfo.h"

class Town
{
private:
	std::wstring name;
	int code;
	//district;
	PopulationInfo *population;

public:
	Town(int code, std::wstring name);
	~Town();
};

