#include "Region.h"
#include "structures\heap_monitor.h"




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
