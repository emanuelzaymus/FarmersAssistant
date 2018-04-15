#include <locale>
#include <codecvt>
#include <string>
#include <iostream>

#include "FileHandler.h"

#include <sstream>
#include <fstream>

#include <algorithm>

#include<clocale>

#include <stdio.h>
#include <windows.h>

std::wstring readFile(const char* filename)
{
	std::wifstream wif(filename);
	wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}

int StringToWString(std::wstring &ws, const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;

	return 0;
}

int main() {
	setlocale(LC_ALL, "");

	FileHandler fh;

	fh.readRegionUTF8("data/Uzemne_clenenie_SR_ZA_changedUTF8.csv");

	//fh.readPopulationUTF8("data/Obyvatelstvo_podla_trvaleho_pobytu_changedUTF8.csv");

	//fh.readLandUTF8("data/Vymera_uzemia_vyuzitie_pody_changedUTF8.csv");

	return 0;
}
