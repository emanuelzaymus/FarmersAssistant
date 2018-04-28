#pragma once

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"

#include "FileHandler.h"
#include "Region.h"

class Manager
{
private:
	FileHandler* fh;
	structures::List<Region*>* regions = new structures::ArrayList<Region*>();

public:
	Manager();
	~Manager();

	void loadInfo();
};

