#pragma once

#include <string>

#include "structures\heap_monitor.h"

#include "PopulationInfo.h"
#include "District.h"

class Town
{
private:
	std::wstring name;
	int code;
	District* district;
	PopulationInfo *population;

public:
	Town(int code, std::wstring name, District* district);
	~Town();
};

