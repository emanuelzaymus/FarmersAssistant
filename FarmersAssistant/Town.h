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
	LandInfo* land = nullptr;

public:
	Town(int code, std::wstring name, District* district);
	~Town();

	auto getName() { return name; }

	void setLandInfo(LandInfo* i) { land = i; }

	District& getDistrict() { return *district; }

	LandInfo& getLandInfo() { return *land; }
};

