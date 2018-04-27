#pragma once

#include <string>

#include "structures\heap_monitor.h"

#include "PopulationInfo.h"

class Region //Kraj
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

