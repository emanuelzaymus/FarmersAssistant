#pragma once

#include <string>

#include "PopulationInfo.h"

class Region
{
private:
	std::wstring name;
	int code;
	//districts
	PopulationInfo *population;

public:
	Region(int code, std::wstring name);
	~Region();
};

