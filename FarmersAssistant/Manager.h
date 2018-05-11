#pragma once

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\table\sorted_sequence_table_string.h"
#include "structures\priority_queue\heap.h"

#include "FileHandler.h"
#include "Region.h"

class Manager
{
private:
	FileHandler* fh;
	structures::List<Region*>* regions = new structures::ArrayList<Region*>();

	structures::Table<std::wstring, structures::LinkedList<Town*>>* alphabeticalTowns = new structures::SortedSequenceTableString<std::wstring, structures::LinkedList<Town*>>();

	structures::LinkedList<Town*>* allTowns = new structures::LinkedList<Town*>();

	void setAttributes();

public:
	Manager();
	~Manager();

	void loadInfo();

	structures::LinkedList<Town*> getTown(std::wstring name);

	structures::Heap<Town*> getTownsByArea(int year);
};

