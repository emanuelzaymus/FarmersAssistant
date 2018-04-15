#include "FileHandler.h"

#include <iostream>

#include <fstream>
#include <sstream>
#include <codecvt>
#include <string>


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
	wifstrm.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	
	if (!wifstrm.is_open())
		throw std::exception("Cannot open file.");

	std::wstring wstr;
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

void FileHandler::readPopulationUTF8(std::string path)
{
	std::wifstream wifstrm(path);
	wifstrm.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

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
	wifstrm.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

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
