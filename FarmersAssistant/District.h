#pragma once

#include <string>

#include "structures\heap_monitor.h"

#include "PopulationInfo.h"
#include "Region.h"

class District //Okres
{
private:
	std::wstring name;
	int code;
	Region* region;
	//towns
	PopulationInfo *population;

public:
	District(int code, std::wstring name, Region* region);
	~District();
};

