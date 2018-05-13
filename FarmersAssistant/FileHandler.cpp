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
#include "structures\list\linked_list.h"
#include "structures\table\sorted_sequence_table_string.h"

#include "Town.h"
#include "District.h"
#include "PopulationInfo.h"
#include "LandInfo.h"

std::wstring FileHandler::trimComma(std::wstring wstr, std::wstring& district)
{
	int comma = wstr.find(L',');
	if (comma > 0)
	{
		district = wstr.substr(comma + 8);
		wstr = wstr.substr(0, comma);
	}
	return wstr;
}

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
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

	//int i = 0;
	while (wifstrm.good())
	{
		//if (i++ >= 50)
		//	break;
		std::getline(wifstrm, wstr, L';');

		std::getline(wifstrm, wstr, L';');
		townCode = std::stoi(wstr);
		//std::wcout << townCode << '|';

		std::getline(wifstrm, townName, L';');
		townName = townName.substr(2);
		//std::wcout << townName << '|';

		std::getline(wifstrm, wstr, L';');
		districtCode = std::stoi(wstr);
		//std::wcout << districtCode << '|';

		if (districtCode != lastNewDistrictCode)
		{
			std::getline(wifstrm, districtName, L';');
			//std::wcout << districtName << '|';

			lastNewDistrictCode = districtCode;

			if (firstRecord)
			{
				std::getline(wifstrm, wstr, L';');
				regionCode = std::stoi(wstr);
				//std::wcout << regionCode << '|';

				std::getline(wifstrm, regionName, L'\n');
				//std::wcout << regionName << '|';

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
		//std::wcout << std::endl;
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
		delete info;
	}
	wifstrm.close();
}

void FileHandler::readLandUTF8(std::string path, structures::List<Region*> &regions)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
	std::wstring name;
	std::wstring district;
	std::wstring area;

	LandInfo* landInfo = nullptr;
	structures::Array<int>* arr;

	for (size_t i = 0; i < 14; i++) { std::getline(wifstrm, wstr); }//first line with descreptions + 14 lines
	std::getline(wifstrm, name, L';');//name

	while (wifstrm.good())
	{
		for each (auto region in regions)
		{
			structures::SortedSequenceTableString<std::wstring, structures::LinkedList<Town*>> townTable = region->getSortedTowns();
			std::wcout << region->getName() << std::endl;

			for (size_t i = 0; i < region->getNumberOfTowns(); i++)
			{
				name = trimComma(name, district);
				//std::wcout << '*' << name << "*|";

				Town* town = nullptr;
				try
				{
					structures::LinkedList<Town*> townList = townTable[name];
					if (townList.size() == 1)
						town = townList[0];
					else
						for each (Town* t in townList)
							if (t->getDistrict().getName().compare(district) == 0)
								town = t;
				}
				catch (const std::exception& e)
				{
					std::wcout << "-->" << name << "<--|";
					std::cout << e.what() << std::endl;
					std::getline(wifstrm, wstr);
					std::getline(wifstrm, name, L';');//name
					return;
				}
				//std::cout << std::endl;

				landInfo = new LandInfo();
				for (size_t i = 0; i < 2; i++) { std::getline(wifstrm, wstr, L'\n'); } //Total Area, Total Agricultural Area
				std::getline(wifstrm, wstr, L';'); //empty space

				do
				{
					std::getline(wifstrm, area, L';'); //name of area

					if (area.compare(L"Nepo¾nohospodárska pôda - spolu") == 0) {
						std::getline(wifstrm, wstr, L'\n');
						std::getline(wifstrm, wstr, L';'); //empty space
						continue;
					}

					arr = new structures::Array<int>(LandInfo::MAX_YEAR - LandInfo::MIN_YEAR + 1);
					for (size_t j = 0; j < LandInfo::MAX_YEAR - LandInfo::MIN_YEAR + 1; j++)
					{
						if (j < LandInfo::MAX_YEAR - LandInfo::MIN_YEAR)
							std::getline(wifstrm, wstr, L';');
						else
							std::getline(wifstrm, wstr, L'\n');

						(*arr)[j] = std::stoi(wstr);
						//std::wcout << (*arr)[j] << '|';
					}
					//std::cout << std::endl;

					if (area.compare(L"Po¾nohospodárska pôda  - orná pôda (v m2)") == 0) { landInfo->setArableLand(arr); }
					else if (area.compare(L"Po¾nohospodárska pôda  - chme¾nica (v m2)") == 0) { landInfo->setHopGarden(arr); }
					else if (area.compare(L"Po¾nohospodárska pôda  - vinica (v m2)") == 0) { landInfo->setVineyard(arr); }
					else if (area.compare(L"Po¾nohospodárska pôda  -  záhrada") == 0) { landInfo->setGarden(arr); }
					else if (area.compare(L"Po¾nohospodárska pôda  -  ovocný sad (v m2)") == 0) { landInfo->setOchard(arr); }
					else if (area.compare(L"Po¾nohospodárska pôda  -  trvalý trávny porast (v m2)") == 0) { landInfo->setLawn(arr); }

					else if (area.compare(L"Nepo¾nohospodárska pôda - lesný pozemok (v m2)") == 0) { landInfo->setForest(arr); }
					else if (area.compare(L"Nepo¾nohospodárska pôda - vodná plocha (v m2)") == 0) { landInfo->setWater(arr); }
					else if (area.compare(L"Nepo¾nohospodárska pôda - zastavaná plocha a nádvorie (v m2)") == 0) { landInfo->setBuiltupArea(arr); }
					else if (area.compare(L"Nepo¾nohospodárska pôda - ostatná plocha (v m2)") == 0) { landInfo->setTheRest(arr); }
					else { std::wcout << "error|"; }
					std::getline(wifstrm, name, L';');

				} while (name.compare(L"") == 0);

				town->setLandInfo(landInfo);
			}
		}

		wifstrm.close();
		std::cout << "---------------" << std::endl;
		return;
	}
}

std::wstring FileHandler::removeDiacritic(std::wstring wstr)
{
	for (size_t i = 0; i < wstr.length(); i++)
	{
		switch (wstr.at(i))
		{
		case L'á': wstr[i] = L'a'; break;
		case L'ä': wstr[i] = L'a'; break;
		case L'è': wstr[i] = L'c'; break;
		case L'ï': wstr[i] = L'd'; break;
		case L'é': wstr[i] = L'e'; break;
		case L'í': wstr[i] = L'i'; break;
		case L'å': wstr[i] = L'l'; break;
		case L'¾': wstr[i] = L'l'; break;
		case L'ò': wstr[i] = L'n'; break;
		case L'ó': wstr[i] = L'o'; break;
		case L'ô': wstr[i] = L'o'; break;
		case L'à': wstr[i] = L'r'; break;
		case L'š': wstr[i] = L's'; break;
		case L'': wstr[i] = L't'; break;
		case L'ú': wstr[i] = L'u'; break;
		case L'ý': wstr[i] = L'y'; break;
		case L'ž': wstr[i] = L'z'; break;

		case L'Á': wstr[i] = L'A'; break;
		case L'Ä': wstr[i] = L'A'; break;
		case L'È': wstr[i] = L'C'; break;
		case L'Ï': wstr[i] = L'D'; break;
		case L'É': wstr[i] = L'E'; break;
		case L'Í': wstr[i] = L'I'; break;
		case L'Å': wstr[i] = L'L'; break;
		case L'¼': wstr[i] = L'L'; break;
		case L'Ò': wstr[i] = L'N'; break;
		case L'Ó': wstr[i] = L'O'; break;
		case L'Ô': wstr[i] = L'O'; break;
		case L'À': wstr[i] = L'R'; break;
		case L'Š': wstr[i] = L'S'; break;
		case L'': wstr[i] = L'T'; break;
		case L'Ú': wstr[i] = L'U'; break;
		case L'Ý': wstr[i] = L'Y'; break;
		case L'Ž': wstr[i] = L'Z'; break;

		case L' ': wstr[i] = L'_'; break;

		default: break;
		}
	}
	return wstr;
}
