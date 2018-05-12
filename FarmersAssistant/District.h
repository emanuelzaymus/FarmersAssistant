#pragma once

#include <string>

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\list\linked_list.h"

#include "PopulationInfo.h"
class Region;
#include "Town.h"

class District //Okres
{
private:
	std::wstring name;
	int code;
	Region* region;
	structures::LinkedList<Town*>* towns = new structures::LinkedList<Town*>();
	PopulationInfo *population;
	int townsCount = 0;

public:
	District(int code, std::wstring name, Region* region);
	~District();

	void addTown(Town* t) { towns->add(t); townsCount++; }
	structures::LinkedList<Town*>& getTowns() { return *towns; }
	std::wstring getName() { return name; }
	int getNumberOfTowns() { return townsCount; }
	Region* getRegion() { return region; }

	int getArableLand(int year);
	int getHopGarden(int year);
	int getVineyard(int year);
	int getGarden(int year);
	int getOchard(int year);
	int getLawn(int year);
	int getForest(int year);
	int getWater(int year);
	int getBuiltupArea(int year);
	int getTheRest(int year);

	int getTotalArea(int year);
};

