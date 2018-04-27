#pragma once

#include "structures\heap_monitor.h"

#include "FileHandler.h"

class Manager
{
private:
	FileHandler* fh;

public:
	Manager();
	~Manager();
};

