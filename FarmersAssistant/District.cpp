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
