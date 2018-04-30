#include "FileHandler.h"

#include <iostream>

#include <fstream>
#include <sstream>
#include <codecvt>
#include <string>

#include <locale>
#include <codecvt>

#include "structures\heap_monitor.h"
#include "structures\array\array.h"

#include "Town.h"
#include "District.h"
#include "PopulationInfo.h"
#include "LandInfo.h"

FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

void FileHandler::read(std::string path)
{
	std::ifstream inFile(path);

	if (!inFile.is_open())
	{
		std::cout << "File is not open" << std::endl;
		return;
	}

	std::string s;
	std::getline(inFile, s);
	while (inFile.good())
	{
		std::getline(inFile, s, ';');
		std::cout << s << '|';
	}
}

Region* FileHandler::readRegionUTF8(std::string path)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
	int townCode;
	std::wstring townName;
	int districtCode;
	int lastNewDistrictCode = -20000;
	std::wstring districtName;
	int regionCode;
	std::wstring regionName;

	bool firstRecord = true;

	Region* region = nullptr;
	District* district = nullptr;
	Town* town;

	std::getline(wifstrm, wstr);

	int i = 0;
	while (wifstrm.good())
	{
		//if (i++ >= 50)
		//	break;
		std::getline(wifstrm, wstr, L';');

		std::getline(wifstrm, wstr, L';');
		townCode = std::stoi(wstr);
		std::wcout << townCode << '|';

		std::getline(wifstrm, townName, L';');
		townName = townName.substr(2);
		std::wcout << townName << '|';

		std::getline(wifstrm, wstr, L';');
		districtCode = std::stoi(wstr);
		std::wcout << districtCode << '|';

		if (districtCode != lastNewDistrictCode)
		{
			std::getline(wifstrm, districtName, L';');
			std::wcout << districtName << '|';

			lastNewDistrictCode = districtCode;

			if (firstRecord)
			{
				std::getline(wifstrm, wstr, L';');
				regionCode = std::stoi(wstr);
				std::wcout << regionCode << '|';

				std::getline(wifstrm, regionName, L'\n');
				std::wcout << regionName << '|';

				region = new Region(regionCode, regionName);

				firstRecord = false;
			}
			else {
				std::getline(wifstrm, wstr, L'\n');
			}
			district = new District(districtCode, districtName, region);
		}
		else {
			std::getline(wifstrm, wstr, L'\n');
		}
		town = new Town(townCode, townName, district);
		std::wcout << std::endl;

	}
	wifstrm.close();

	return region;
}

void FileHandler::readPopulationUTF8(std::string path)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
	std::wstring name;
	int men;
	int women;

	std::getline(wifstrm, wstr);
	std::getline(wifstrm, wstr);
	int i = 0;
	while (wifstrm.good())
	{
		if (i++ >= 3)
		{
			break;
		}

		std::getline(wifstrm, name, L';');
		std::wcout << name << '|';

		PopulationInfo* info = new PopulationInfo();

		for (size_t j = 0; j < PopulationInfo::POPUL_GROUPS; j++)
		{
			std::getline(wifstrm, wstr, L';');

			std::getline(wifstrm, wstr, L';');
			men = std::stoi(wstr);
			std::wcout << men << '|';
			std::getline(wifstrm, wstr, L';');
			women = std::stoi(wstr);
			std::wcout << wstr << '|';

			if (j < PopulationInfo::POPUL_GROUPS - 1)
			{
				std::getline(wifstrm, wstr, L';');
			}
			else {
				std::getline(wifstrm, wstr, L'\n');
			}
			info->addCountIn5Years(j, men, women);
		}
		std::cout << std::endl;
		delete info;// find appropriate town and put info into it !!! TODO
	}
	wifstrm.close();
}

void FileHandler::readLandUTF8(std::string path)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
	std::wstring name;

	LandInfo* landInfo;
	structures::Array<int>* array;
	
	std::getline(wifstrm, wstr);
	int i = 0;
	while (wifstrm.good())
	{
		if (i++ >= 10)
		{
			break;
		}

		std::getline(wifstrm, name, L';');
		std::wcout << "*****" << name << "*****" << '|';
		landInfo = new LandInfo();

		for (size_t i = 0; i < 13; i++)
		{
			if (i == 0 || i == 1 || i == 8) //Total Area, Total Agricultural Area, Total Nonagricultural Area
			{
				std::getline(wifstrm, wstr, L'\n');
				continue;
			}
			for (size_t i = 0; i < 2; i++) { std::getline(wifstrm, wstr, L';'); } //empty space, name of area

			array = new structures::Array<int>(LandInfo::MAX_YEAR - LandInfo::MIN_YEAR + 1);

			for (size_t j = 0; j < LandInfo::MAX_YEAR - LandInfo::MIN_YEAR + 1; j++)
			{
				if (j < LandInfo::MAX_YEAR - LandInfo::MIN_YEAR)
					std::getline(wifstrm, wstr, L';');
				else
					std::getline(wifstrm, wstr, L'\n');

				(*array)[j] = std::stoi(wstr);
				std::wcout << (*array)[j] << '|';
			}
			switch (i)
			{
			case 2: landInfo->setArableLand(array);	break;
			case 3: landInfo->setHopGarden(array); break;
			case 4: landInfo->setVineyard(array); break;
			case 5: landInfo->setGarden(array);	break;
			case 6: landInfo->setOchard(array);	break;
			case 7: landInfo->setLawn(array); break;
			
			case 9: landInfo->setForest(array); break;
			case 10: landInfo->setWater(array); break;
			case 11: landInfo->setBuiltupArea(array); break;
			case 12: landInfo->setTheRest(array); break;
			}
			std::cout << std::endl;
		}

		delete landInfo;//put landInfo into town you find TODO
	}
	wifstrm.close();
}
