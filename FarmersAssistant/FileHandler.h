#pragma once

#include <string>

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\list\linked_list.h"
#include "structures\table\sorted_sequence_table_string.h"

#include "Region.h"

class FileHandler
{
private:
	std::wstring trimComma(std::wstring wstr, std::wstring& district);

public:
	FileHandler();
	~FileHandler();

	Region* readRegionUTF8(std::string path);
	void readPopulationUTF8(std::string path);
	void readLandUTF8(std::string path, structures::List<Region*> &regions);

	static std::wstring removeDiacritic(std::wstring wstr);

};

