#include "Manager.h"
#include "structures\heap_monitor.h"

#include <iostream>



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

				if (!alphabeticalTowns->containsKey(t->getName()))
				{
					structures::LinkedList<Town*> list;
					list.add(t);
					alphabeticalTowns->insert(t->getName(), list);
				}
				else {
					((*alphabeticalTowns)[t->getName()]).add(t);
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

structures::LinkedList<Town*> Manager::getTown(std::wstring name)
{
	try
	{
		return (*alphabeticalTowns)[name];
	}
	catch (const std::exception&)
	{
		return structures::LinkedList<Town*>();
	}
}

structures::Heap<Town*> Manager::getTownsByArea(int year)
{
	structures::Heap<Town*> ret;

	for each (auto t in *allTowns)
	{
		std::wcout << t->getName() << std::endl;
		ret.push(-t->getLandInfo().getTotalArea(year), t);
	}

	return ret;
}


