#pragma once

#include <string>

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\list\linked_list.h"
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "structures\table\sorted_sequence_table_string.h"

#include "PopulationInfo.h"
#include "District.h"
#include "Town.h"

class Region //Kraj
{
private:
	std::wstring name;
	int code;
	structures::ArrayList<District*>* districts = new structures::ArrayList<District*>();
	PopulationInfo *population;

public:
	Region(int code, std::wstring name);
	~Region();

	void addDistrict(District* d) { districts->add(d); }
	structures::SortedSequenceTableString<std::wstring, structures::LinkedList<Town*>> getSortedTowns();

	auto getName() { return name; }
	int getCode() { return code; }

	structures::ArrayList<District*>& getDistricts() { return *districts; }

	int getNumberOfTowns();
};

