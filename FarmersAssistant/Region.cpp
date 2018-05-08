#include "Region.h"

#include "structures\heap_monitor.h"
#include "structures\table\sorting\shell_sort.h"





Region::Region(int code, std::wstring name)
	: code(code), name(name)
{
}

Region::~Region()
{
	while (!districts->isEmpty())
		delete districts->removeAt(districts->size() - 1);
	delete districts;
}

structures::SortedSequenceTableString<std::wstring, Town*> Region::getSortedTowns()
{
	structures::SortedSequenceTableString<std::wstring, Town*> table;

	for each (auto d in *districts)
	{
		auto towns = d->getTowns();
		for each (auto t in *towns)
		{
			table.insert(t->getName(), t);
		}
	}

	return table;
}

structures::SortedSequenceTable<std::wstring, Town*> Region::getTowns()
{
	structures::SortedSequenceTable<std::wstring, Town*> table;

	for each (auto d in *districts)
	{
		auto towns = d->getTowns();
		for each (auto t in *towns)
		{
			table.insert(t->getName(), t);
		}
	}

	return table;
}
