#pragma once

#include <string>

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"

#include "PopulationInfo.h"
#include "District.h"

class Region //Kraj
{
private:
	std::wstring name;
	int code;
	structures::List<District*>* districts = new structures::ArrayList<District*>();
	PopulationInfo *population;

public:
	Region(int code, std::wstring name);
	~Region();

	void addDistrict(District* d) { districts->add(d); }
};

