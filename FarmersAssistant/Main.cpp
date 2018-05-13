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
	std::wstring aaa = L"abcd¾šèž";
	//std::wcin >> aaa;

	std::wcout << aaa.length() << std::endl;

	for (size_t i = 0; i < aaa.length(); i++)
	{
		switch (aaa.at(i))
		{
		case L'á': aaa[i] = L'a'; break;
		case L'ä': aaa[i] = L'a'; break;
		case L'è': aaa[i] = L'c'; break;
		case L'ï': aaa[i] = L'd'; break;
		case L'é': aaa[i] = L'e'; break;
		case L'í': aaa[i] = L'i'; break;
		case L'å': aaa[i] = L'l'; break;
		case L'¾': aaa[i] = L'l'; break;
		case L'ò': aaa[i] = L'n'; break;
		case L'ó': aaa[i] = L'o'; break;
		case L'ô': aaa[i] = L'o'; break;
		case L'à': aaa[i] = L'r'; break;
		case L'š': aaa[i] = L's'; break;
		case L'': aaa[i] = L't'; break;
		case L'ú': aaa[i] = L'u'; break;
		case L'ý': aaa[i] = L'y'; break;
		case L'ž': aaa[i] = L'z'; break;
		
		case L'Á': aaa[i] = L'A'; break;
		case L'Ä': aaa[i] = L'A'; break;
		case L'È': aaa[i] = L'C'; break;
		case L'Ï': aaa[i] = L'D'; break;
		case L'É': aaa[i] = L'E'; break;
		case L'Í': aaa[i] = L'I'; break;
		case L'Å': aaa[i] = L'L'; break;
		case L'¼': aaa[i] = L'L'; break;
		case L'Ò': aaa[i] = L'N'; break;
		case L'Ó': aaa[i] = L'O'; break;
		case L'Ô': aaa[i] = L'O'; break;
		case L'À': aaa[i] = L'R'; break;
		case L'Š': aaa[i] = L'S'; break;
		case L'': aaa[i] = L'T'; break;
		case L'Ú': aaa[i] = L'U'; break;
		case L'Ý': aaa[i] = L'Y'; break;
		case L'Ž': aaa[i] = L'Z'; break;

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

