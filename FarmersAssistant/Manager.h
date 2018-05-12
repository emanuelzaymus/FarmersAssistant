#pragma once

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\table\sorted_sequence_table_string.h"
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "structures\priority_queue\heap.h"
#include "structures\table\treap.h"

#include "FileHandler.h"
#include "Region.h"

enum Order
{
	ASC = 1,
	DESC = -1
};

enum Extreme
{
	MAX,
	MIN
};

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

	structures::SortedSequenceTable<int, structures::LinkedList<Town*>> getTownsByArea(int year, Order order);

	structures::SortedSequenceTable<double, structures::LinkedList<Town*>> townsBuiltupAreaIncrease(int firstYear, int secondYear, Order order);

	structures::SortedSequenceTable<double, structures::LinkedList<Town*>> townsArableLandRatioDifference(int firstYear, int secondYear, Order order);

	structures::LinkedList<District*> districtByOchard(int year, Extreme extrem);

	structures::LinkedList<District*> districtByArableOchardRatio(int year, Extreme extrem);

	structures::LinkedList<District*> districtByForestRatio(int year, Extreme extrem);

	structures::SortedSequenceTable<double, structures::LinkedList<District*>> districtsOchardRatioDifference(int firstYear, int secondYear, Order order);

	structures::SortedSequenceTable<double, structures::LinkedList<District*>> districtsArableLandRatioDifference(int firstYear, int secondYear, Order order);

	structures::SortedSequenceTable<double, structures::LinkedList<District*>> districtsForestRatioDifference(int firstYear, int secondYear, Order order);

};

