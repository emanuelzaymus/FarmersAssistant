#include "District.h"
#include "structures\heap_monitor.h"




District::District(int code, std::wstring name, Region* region)
	: code(code), name(name), region(region)
{
}

District::~District()
{
}
