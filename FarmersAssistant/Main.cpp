#include <locale>
#include <codecvt>
#include <string>
#include <iostream>

#include "structures\heap_monitor.h"

#include "Manager.h"

#include <sstream>
#include <fstream>

#include <algorithm>

#include<clocale>

#include <stdio.h>
#include <windows.h>

//std::wstring readFile(const char* filename)
//{
//	std::wifstream wif(filename);
//	wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
//	std::wstringstream wss;
//	wss << wif.rdbuf();
//	return wss.str();
//}
//
//int StringToWString(std::wstring &ws, const std::string &s)
//{
//	std::wstring wsTmp(s.begin(), s.end());
//
//	ws = wsTmp;
//
//	return 0;
//}

int main() {
	initHeapMonitor();

	setlocale(LC_ALL, "");

	Manager manager;

	manager.loadInfo();

	return 0;
}
