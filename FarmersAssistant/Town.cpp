#include "Town.h"
#include "structures\heap_monitor.h"

#include "District.h"


Town::Town(int code, std::wstring name, District* district)
	: code(code), name(name), district(district)
{
	district->addTown(this);
}

Town::~Town()
{
	//delete population;
}
