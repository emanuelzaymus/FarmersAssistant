#pragma once

#include <string>

class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	void read(std::string path);
	void readRegionUTF8(std::string path);
	void readPopulationUTF8(std::string path);
	void readLandUTF8(std::string path);
};

