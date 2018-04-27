#include "FileHandler.h"

#include <iostream>

#include <fstream>
#include <sstream>
#include <codecvt>
#include <string>

#include <locale>
#include <codecvt>

#include "structures\heap_monitor.h"

#include "Town.h"
#include "District.h"
#include "Region.h"


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

void FileHandler::readRegionUTF8(std::string path)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
	int townCode;
	std::wstring townName;
	int districtCode;
	std::wstring districtName;
	int regionCode;
	std::wstring regionName;

	Region* region;
	District* district;

	std::getline(wifstrm, wstr);

	int i = 0;
	while (wifstrm.good())
	{
		if (i++ >= 50)
			break;
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
		
		std::getline(wifstrm, districtName, L';');
		std::wcout << districtName << '|';
		
		std::getline(wifstrm, wstr, L';');
		regionCode = std::stoi(wstr);
		std::wcout << regionCode << '|';
		
		std::getline(wifstrm, regionName, L'\n');
		std::wcout << regionName << '|' << std::endl;


	}
	wifstrm.close();
}

void FileHandler::readPopulationUTF8(std::string path)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
	std::getline(wifstrm, wstr);
	std::getline(wifstrm, wstr);
	int i = 0;
	while (wifstrm.good())
	{
		if (i++ >= 500)
		{
			break;
		}
		std::getline(wifstrm, wstr, L';');
		std::wcout << wstr << '|';
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
	//std::getline(wifstrm, wstr);
	int i = 0;
	while (wifstrm.good())
	{
		if (i++ >= 500)
		{
			break;
		}
		std::getline(wifstrm, wstr, L';');
		std::wcout << wstr << '|';
	}
	wifstrm.close();
}
