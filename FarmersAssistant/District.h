#pragma once

#include <string>

#include "PopulationInfo.h"

class District
{
private:
	std::wstring name;
	int code;
	//region
	//towns
	PopulationInfo *population;

public:
	District(int code, std::wstring name);
	~District();
};

