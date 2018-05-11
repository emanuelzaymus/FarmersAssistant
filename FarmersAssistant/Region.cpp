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

structures::SortedSequenceTableString<std::wstring, structures::LinkedList<Town*>> Region::getSortedTowns()
{
	structures::SortedSequenceTableString<std::wstring, structures::LinkedList<Town*>> table;

	for each (auto d in *districts)
	{
		auto towns = d->getTowns();
		for each (auto t in towns)
		{
			if (!table.containsKey(t->getName()))
			{
				structures::LinkedList<Town*> list;
				list.add(t);
				table.insert(t->getName(), list);
			}
			else {
				table[t->getName()].add(t);
			}
		}
	}

	return table;
}

int Region::getNumberOfTowns()
{
	int count = 0;
	for each (auto d in *districts)
	{
		count += d->getNumberOfTowns();
	}

	return count;
}
