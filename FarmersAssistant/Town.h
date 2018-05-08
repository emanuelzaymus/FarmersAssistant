#pragma once

#include <string>

#include "structures\heap_monitor.h"

#include "PopulationInfo.h"
#include "LandInfo.h"
class District;

class Town
{
private:
	std::wstring name;
	int code;
	District* district;
	PopulationInfo *population;
	LandInfo* land;

public:
	Town(int code, std::wstring name, District* district);
	~Town();

	auto getName() { return name; }

	void setLandInfo(LandInfo* i) { land = i; }
};

