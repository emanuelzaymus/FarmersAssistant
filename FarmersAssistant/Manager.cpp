#include "Manager.h"
#include "structures\heap_monitor.h"

#include <iostream>

#include "structures\table\sorting\shell_sort.h"



void Manager::setAttributes()
{
	for each (Region* r in *regions)
	{
		auto districts = r->getDistricts();
		for each (District* d in districts)
		{
			auto towns = d->getTowns();
			for each (Town*	 t in towns)
			{
				allTowns->add(t);
				std::wstring noDiacriticName = FileHandler::removeDiacritic(t->getName());
				if (!alphabeticalTowns->containsKey(noDiacriticName))
				{
					structures::LinkedList<Town*> list;
					list.add(t);
					alphabeticalTowns->insert(noDiacriticName, list);
				}
				else {
					((*alphabeticalTowns)[noDiacriticName]).add(t);
				}
			}
		}
	}

}


Manager::Manager()
{
	fh = new FileHandler();
}


Manager::~Manager()
{
	while (!regions->isEmpty())
		delete regions->removeAt(regions->size() - 1);
	delete regions;

	delete fh;

	delete alphabeticalTowns;
	delete allTowns;
}

void Manager::loadInfo()
{
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_BA_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_TT_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_TN_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_NR_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_ZA_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_BB_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_PO_changed.csv"));
	regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_KE_changed.csv"));

	fh->readLandUTF8("data/Vymera_uzemia_vyuzitie_pody_changed.csv", *regions);

	//fh->readPopulationUTF8("data/Obyvatelstvo_podla_trvaleho_pobytu_changed.csv");

	setAttributes();

}

structures::LinkedList<Town*> Manager::getTown(std::wstring noDiacriticName)
{
	try
	{
		return (*alphabeticalTowns)[noDiacriticName];
	}
	catch (const std::exception&)
	{
		return structures::LinkedList<Town*>();
	}
}

structures::SortedSequenceTable<int, structures::LinkedList<Town*>> Manager::getTownsByArea(int year, Order order)
{
	structures::SortedSequenceTable<int, structures::LinkedList<Town*>> table;

	for each (auto t in *allTowns)
	{
		int totalArea = t->getLandInfo()->getTotalArea(year);

		if (!table.containsKey(order * totalArea))
		{
			structures::LinkedList<Town*> list;
			list.add(t);
			table.insert(order * totalArea, list);
		}
		else {
			table[order * totalArea].add(t);
		}
	}
	return table;
}

structures::SortedSequenceTable<double, structures::LinkedList<Town*>> Manager::townsBuiltupAreaIncrease(int firstYear, int secondYear, Order order)
{
	structures::SortedSequenceTable<double, structures::LinkedList<Town*>> table;

	for each (auto t in *allTowns)
	{
		auto landInfo = t->getLandInfo();
		double second = landInfo->getBuiltupArea(secondYear) / (double)landInfo->getTotalArea(secondYear);
		double first = landInfo->getBuiltupArea(firstYear) / (double)landInfo->getTotalArea(firstYear);
		double increase = second - first;

		if (!table.containsKey(order * increase))
		{
			structures::LinkedList<Town*> list;
			list.add(t);
			table.insert(order * increase, list);
		}
		else {
			table[order * increase].add(t);
		}
	}
	return table;
}

structures::SortedSequenceTable<double, structures::LinkedList<Town*>> Manager::townsArableLandRatioDifference(int firstYear, int secondYear, Order order)
{
	structures::SortedSequenceTable<double, structures::LinkedList<Town*>> table;

	for each (auto t in *allTowns)
	{
		auto landInfo = t->getLandInfo();
		double increase = landInfo->getArableLand(secondYear) / (double)landInfo->getTotalArea(secondYear)
			- landInfo->getArableLand(firstYear) / (double)landInfo->getTotalArea(firstYear);

		if (!table.containsKey(order * increase))
		{
			structures::LinkedList<Town*> list;
			list.add(t);
			table.insert(order * increase, list);
		}
		else {
			table[order * increase].add(t);
		}
	}
	return table;
}

structures::LinkedList<District*> Manager::districtByOchard(int year, Extreme extrem)
{
	structures::LinkedList<District*> ret;
	int ochardArea = 10000000;
	for each (Region* r in *regions)
	{
		for each (District* d in r->getDistricts())
		{
			int area = d->getOchard(year);
			if (ochardArea == area)
			{
				ret.add(d);
			}
			else {
				if (extrem == Extreme::MAX)
				{
					if (ret.isEmpty() || ochardArea < area) {
						ochardArea = area;
						ret.clear();
						ret.add(d);
					}
				}
				else {
					if (ret.isEmpty() || ochardArea > area) {
						ochardArea = area;
						ret.clear();
						ret.add(d);
					}
				}
			}

		}
	}
	return ret;
}

structures::LinkedList<District*> Manager::districtByArableOchardRatio(int year, Extreme extrem)
{
	structures::LinkedList<District*> ret;
	double arableOchardRatio = 10000000;
	for each (Region* r in *regions)
	{
		for each (District* d in r->getDistricts())
		{
			double ratio = (double)d->getOchard(year) == 0 ? 0 : d->getArableLand(year) / (double)d->getOchard(year);
			if (arableOchardRatio == ratio)
			{
				ret.add(d);
			}
			else {
				if (extrem == Extreme::MAX)
				{
					if (ret.isEmpty() || arableOchardRatio < ratio) {
						arableOchardRatio = ratio;
						ret.clear();
						ret.add(d);
					}
				}
				else {
					if (ret.isEmpty() || arableOchardRatio > ratio) {
						arableOchardRatio = ratio;
						ret.clear();
						ret.add(d);
					}
				}
			}

		}
	}
	return ret;
}

structures::LinkedList<District*> Manager::districtByForestRatio(int year, Extreme extrem)
{
	structures::LinkedList<District*> ret;
	double forestRatio = 10000000;
	for each (Region* r in *regions)
	{
		for each (District* d in r->getDistricts())
		{
			double ratio = d->getForest(year) / (double)d->getTotalArea(year);
			if (forestRatio == ratio)
			{
				ret.add(d);
			}
			else {
				if (extrem == Extreme::MAX)
				{
					if (ret.isEmpty() || forestRatio < ratio) {
						forestRatio = ratio;
						ret.clear();
						ret.add(d);
					}
				}
				else {
					if (ret.isEmpty() || forestRatio > ratio) {
						forestRatio = ratio;
						ret.clear();
						ret.add(d);
					}
				}
			}

		}
	}
	return ret;
}

structures::SortedSequenceTable<double, structures::LinkedList<District*>> Manager::districtsOchardRatioDifference(int firstYear, int secondYear, Order order)
{
	structures::SortedSequenceTable<double, structures::LinkedList<District*>> table;

	for each (Region* r in *regions)
	{
		for each (District* d in r->getDistricts())
		{
			double firstRatio = d->getForest(firstYear) / (double)d->getTotalArea(firstYear);
			double secondRatio = d->getForest(secondYear) / (double)d->getTotalArea(secondYear);
			double difference = secondRatio - firstRatio;

			if (!table.containsKey(order * difference))
			{
				structures::LinkedList<District*> list;
				list.add(d);
				table.insert(order * difference, list);
			}
			else {
				table[order * difference].add(d);
			}
		}
	}
	return table;
}

structures::SortedSequenceTable<double, structures::LinkedList<District*>> Manager::districtsArableLandRatioDifference(int firstYear, int secondYear, Order order)
{
	structures::SortedSequenceTable<double, structures::LinkedList<District*>> table;

	for each (Region* r in *regions)
	{
		for each (District* d in r->getDistricts())
		{
			double firstRatio = d->getArableLand(firstYear) / (double)d->getTotalArea(firstYear);
			double secondRatio = d->getArableLand(secondYear) / (double)d->getTotalArea(secondYear);
			double difference = secondRatio - firstRatio;

			if (!table.containsKey(order * difference))
			{
				structures::LinkedList<District*> list;
				list.add(d);
				table.insert(order * difference, list);
			}
			else {
				table[order * difference].add(d);
			}
		}
	}
	return table;
}

structures::SortedSequenceTable<double, structures::LinkedList<District*>> Manager::districtsForestRatioDifference(int firstYear, int secondYear, Order order)
{
	structures::SortedSequenceTable<double, structures::LinkedList<District*>> table;

	for each (Region* r in *regions)
	{
		for each (District* d in r->getDistricts())
		{
			double firstRatio = d->getForest(firstYear) / (double)d->getTotalArea(firstYear);
			double secondRatio = d->getForest(secondYear) / (double)d->getTotalArea(secondYear);
			double difference = secondRatio - firstRatio;

			if (!table.containsKey(order * difference))
			{
				structures::LinkedList<District*> list;
				list.add(d);
				table.insert(order * difference, list);
			}
			else {
				table[order * difference].add(d);
			}
		}
	}
	return table;
}

