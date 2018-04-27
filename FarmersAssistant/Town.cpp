#include "Town.h"
#include "structures\heap_monitor.h"




Town::Town(int code, std::wstring name, District* district)
	: code(code), name(name), district(district)
{
}

Town::~Town()
{
}
