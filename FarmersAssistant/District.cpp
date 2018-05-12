#include "District.h"
#include "structures\heap_monitor.h"

#include "Region.h"


District::District(int code, std::wstring name, Region* region)
	: code(code), name(name), region(region)
{
	region->addDistrict(this);
}

District::~District()
{
	while (!towns->isEmpty())
		delete towns->removeAt(towns->size() - 1);
	delete towns;
}

int District::getArableLand(int year)
{
	int area = 0;
	for each (Town* t in *towns)
	{
		area += t->getLandInfo()->getArableLand(year);
	}
	return area;
}

int District::getOchard(int year)
{
	int area = 0;
	for each (Town* t in *towns)
	{
		area += t->getLandInfo()->getOchard(year);
	}
	return area;
}

int District::getForest(int year)
{
	int area = 0;
	for each (Town* t in *towns)
	{
		area += t->getLandInfo()->getForest(year);
	}
	return area;
}

int District::getTotalArea(int year)
{
	int area = 0;
	for each (Town* t in *towns)
	{
		area += t->getLandInfo()->getTotalArea(year);
	}
	return area;
}
