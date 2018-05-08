#pragma once

#include <string>

#include "structures\heap_monitor.h"

//class Manager;
#include "Region.h"

class FileHandler
{
private:
	std::wstring trimComma(std::wstring wstr);

public:
	FileHandler();
	~FileHandler();

	void read(std::string path);
	Region* readRegionUTF8(std::string path);
	void readPopulationUTF8(std::string path);
	void readLandUTF8(std::string path, Region& region, int fromLine);

};

