#include <locale>
#include <codecvt>
#include <string>
#include <iostream>

#include "structures\heap_monitor.h"
#include "structures\tree\k_way_tree.h"
#include "structures\tree\multi_way_tree.h"
#include "structures\tree\binary_tree.h"

#include "structures\table\binary_search_tree.h"
#include "structures\table\treap.h"
#include "structures\tree\tree.h"

#include "structures\table\hash_table.h"

#include "structures\table\table.h"
#include "structures\list\list.h"
#include "structures\tree\binary_tree.h"

#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorting\bubble_sort.h"
#include "structures\table\sorting\heap_sort.h"
#include "structures\table\sorting\insert_sort.h"
#include "structures\table\sorting\merge_sort.h"
#include "structures\table\sorting\quick_sort.h"
#include "structures\table\sorting\radix_sort.h"
#include "structures\table\sorting\select_sort.h"
#include "structures\table\sorting\shell_sort.h"
#include "structures\table\sorting\shuffle.h"

#include <stdexcept>

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

/*
	structures::Treap<int, char> bst;

	bst.insert(1, 'a');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(2, 'b');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(3, 'c');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(4, 'd');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(5, 'e');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(6, 'f');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(7, 'g');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(8, 'h');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(9, 'i');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(10, 'j');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	std::cout << bst.remove(4) << std::endl;
	std::cout << bst.remove(5) << std::endl;


	bst.insert(11, 'i');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	bst.insert(12, 'j');
	for each (auto c in bst)
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	std::cout << "------------------------------" << std::endl;

	//bst.insert(1, 'h');
	//bst.insert(2, 'h');
	//bst.insert(3, 'h');
	//bst.insert(4, 'h');
	//bst.insert(5, 'h');
	//bst.insert(6, 'h');
	//bst.insert(7, 'h');
	//bst.insert(8, 'h');
	//bst.insert(9, 'h');
	//bst.insert(10, 'h');
	//bst.insert(11, 'h');
	//bst.insert(12, 'h');
	//bst.insert(13, 'h');
	//bst.insert(14, 'h');
	//bst.insert(15, 'h');
	//bst.insert(16, 'h');
	//bst.insert(17, 'h');
	//bst.insert(18, 'h');
	//bst.insert(19, 'h');
	//bst.insert(20, 'h');


	//for each (auto c in bst)
	//{
	//	std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	//}

	std::cout << bst.remove(1) << std::endl;
	std::cout << bst.remove(2) << std::endl;
	//std::cout << bst.remove(3) << std::endl;
	//std::cout << bst.remove(4) << std::endl;
	//std::cout << bst.remove(5) << std::endl;
	//std::cout << bst.remove(6) << std::endl;

	bst.clear();


	//bst.insert(-56, 'h');
	//bst.insert(0, 'h');

	for each (auto c in bst)
	{
		std::cout << (char)c->accessData() << " - " << c->getKey() << std::endl;
	}
*/

/*
	structures::HashTable<int, char> ht;
	ht.insert(1, 'a');
	ht.insert(2, 'a');
	ht.insert(3, 'a');
	ht.insert(4, 'a');
	ht.insert(5, 'a');
	ht.insert(6, 'a');
	ht.insert(7, 'a');
	ht.insert(8, 'a');
	ht.insert(9, 'a');
	ht.insert(10, 'a');
	ht.insert(11, 'a');
	ht.insert(12, 'a');
	ht.insert(13, 'a');
	ht.insert(14, 'a');

	for each (auto var in ht)
		std::cout << var->getKey() << " - " << var->accessData() << std::endl;
	std::cout << "------------------------" << std::endl;

	std::cout << ht.remove(4) << std::endl;

	for each (auto var in ht)
		std::cout << var->getKey() << " - " << var->accessData() << std::endl;
*/

/*
	structures::UnsortedSequenceTable<int, std::string> table;

	table.insert(60, "sesenta");
	table.insert(9, "nueve");
	table.insert(7, "siete");
	table.insert(4, "cuatro");
	table.insert(36, "treinta y seis");
	table.insert(8, "ocho");
	table.insert(1, "uno");
	table.insert(5, "cinco");
	table.insert(6, "seis");
	table.insert(10, "dies");
	table.insert(2, "dos");
	table.insert(11, "once");
	table.insert(12, "doce");
	table.insert(13, "trece");
	table.insert(14, "catorce");
	table.insert(15, "quince");	

	structures::Shuffle<int, std::string> shuf;
	//shuf(table);

	for each (auto v in table)
		std::cout << v->getKey() << " - " << v->accessData() << std::endl;
	std::cout << "--------" << std::endl;
	

	structures::ShellSort<int, std::string> s;
	s.sort(table);


	for each (auto v in table)
		std::cout << v->getKey() << " - " << v->accessData() << std::endl;
	*/
	return 0;
}
