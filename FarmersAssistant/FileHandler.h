#pragma once

#include <string>

#include "structures\heap_monitor.h"
#include "structures\list\array_list.h"
#include "structures\list\linked_list.h"
#include "structures\table\sorted_sequence_table_string.h"

//class Manager;
#include "Region.h"

class FileHandler
{
private:
	std::wstring trimComma(std::wstring wstr, std::wstring& district);

	structures::LinkedList<LandInfo*>* li = new structures::LinkedList<LandInfo*>();
	structures::LinkedList<structures::Array<int>*>* arrs = new structures::LinkedList<structures::Array<int>*>();

public:
	FileHandler();
	~FileHandler();

	void read(std::string path);
	Region* readRegionUTF8(std::string path);
	void readPopulationUTF8(std::string path);
	void readLandUTF8(std::string path, structures::List<Region*> &regions);

	static std::wstring removeDiacritic(std::wstring wstr);

};

