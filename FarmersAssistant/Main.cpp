#include <locale>
#include <codecvt>
#include <string>
#include <iostream>

#include "structures\heap_monitor.h"

#include <stdexcept>
#include <clocale>
#include <stdio.h>
#include <windows.h>

#include "CLI.h"


int main() {
	initHeapMonitor();

	setlocale(LC_ALL, "");


	//std::setlocale(LC_ALL, "");
	//std::wcout.imbue(std::locale(""));

	//std::setlocale(LC_ALL, "");
	//std::wcin.imbue(std::locale(""));

	//std::wcout.imbue(std::locale(""));


	//std::ios_base::sync_with_stdio(false);
	//std::wcin.imbue(std::locale(std::locale::empty(), ::new std::codecvt_utf8<wchar_t>));

/*
	std::wstring aaa = L"abcd��蝞";
	//std::wcin >> aaa;

	std::wcout << aaa.length() << std::endl;

	for (size_t i = 0; i < aaa.length(); i++)
	{
		switch (aaa.at(i))
		{
		case L'�': aaa[i] = L'a'; break;
		case L'�': aaa[i] = L'a'; break;
		case L'�': aaa[i] = L'c'; break;
		case L'�': aaa[i] = L'd'; break;
		case L'�': aaa[i] = L'e'; break;
		case L'�': aaa[i] = L'i'; break;
		case L'�': aaa[i] = L'l'; break;
		case L'�': aaa[i] = L'l'; break;
		case L'�': aaa[i] = L'n'; break;
		case L'�': aaa[i] = L'o'; break;
		case L'�': aaa[i] = L'o'; break;
		case L'�': aaa[i] = L'r'; break;
		case L'�': aaa[i] = L's'; break;
		case L'�': aaa[i] = L't'; break;
		case L'�': aaa[i] = L'u'; break;
		case L'�': aaa[i] = L'y'; break;
		case L'�': aaa[i] = L'z'; break;
		
		case L'�': aaa[i] = L'A'; break;
		case L'�': aaa[i] = L'A'; break;
		case L'�': aaa[i] = L'C'; break;
		case L'�': aaa[i] = L'D'; break;
		case L'�': aaa[i] = L'E'; break;
		case L'�': aaa[i] = L'I'; break;
		case L'�': aaa[i] = L'L'; break;
		case L'�': aaa[i] = L'L'; break;
		case L'�': aaa[i] = L'N'; break;
		case L'�': aaa[i] = L'O'; break;
		case L'�': aaa[i] = L'O'; break;
		case L'�': aaa[i] = L'R'; break;
		case L'�': aaa[i] = L'S'; break;
		case L'�': aaa[i] = L'T'; break;
		case L'�': aaa[i] = L'U'; break;
		case L'�': aaa[i] = L'Y'; break;
		case L'�': aaa[i] = L'Z'; break;

		default:
			break;
		}
	}

	std::wcout << aaa << std::endl;

	*/


	//char input[100];
	//std::cin.getline(input, sizeof(input));


	CLI cli;

	cli.run();

	//char input[100];
	//std::cin.getline(input, sizeof(input));

	return 0;
}

