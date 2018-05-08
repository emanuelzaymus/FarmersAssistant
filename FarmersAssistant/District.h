#pragma once

#include <string>

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"

#include "PopulationInfo.h"
class Region;
#include "Town.h"

class District //Okres
{
private:
	std::wstring name;
	int code;
	Region* region;
	structures::List<Town*>* towns;
	PopulationInfo *population;

public:
	District(int code, std::wstring name, Region* region);
	~District();

	void addTown(Town* t) { towns->add(t); }

	auto getTowns() { return towns; }
};

