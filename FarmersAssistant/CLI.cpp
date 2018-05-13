#include "CLI.h"

#include "structures\heap_monitor.h"

#include "Manager.h"

#include <iostream>
#include <string>


int CLI::printMenu()
{
	std::cout << " 1 - 1.  Town by Name" << std::endl;
	std::cout << " 2 - 2.a Towns by Total Area" << std::endl;
	std::cout << " 3 - 2.b Towns by Builtup Area Increase" << std::endl;
	std::cout << " 4 - 2.c Towns by Arable Land Ratio Difference" << std::endl;
	std::cout << " 5 - 3.a District by Ochard" << std::endl;
	std::cout << " 6 - 3.b District by Arable Land Ratio" << std::endl;
	std::cout << " 7 - 3.c District by Forest Ratio" << std::endl;
	std::cout << " 8 - 4.a District by Ochard Ratio Difference" << std::endl;
	std::cout << " 9 - 4.b District by Arable Land Ratio Difference" << std::endl;
	std::cout << "10 - 4.c District by Forest Ratio Difference" << std::endl << std::endl;

	std::cout << "11 - End" << std::endl;

	int choice;
	std::cin >> choice;
	system("cls");
	return choice;
}

void CLI::townByName()
{
	std::wcout << "Name of town without diaritic " << L"(e.g.: Malý Lapáš -> Maly_Lapas): ";
	std::wstring town;
	std::wcin >> town;

	int firstYear = readYear(Year::FROM);
	int secondYear = readYear(Year::TO);
	auto towns = manager->getTown(town);
	std::cout << std::endl;

	for each (auto t in towns)
	{
		std::wcout << t->getName() << "  (District: " << t->getDistrict().getName()
			<< ", Region: " << t->getDistrict().getRegion()->getName() << ")" << std::endl << std::endl;

		auto info = t->getLandInfo();
		for (size_t i = firstYear; i <= secondYear; i++)
		{
			std::wcout << "Year: " << i << std::endl;
			std::wcout << "Total area: " << info->getTotalArea(i) << std::endl;
			std::wcout << "Arable land: " << info->getArableLand(i) << std::endl;
			std::wcout << "Ochard: " << info->getOchard(i) << std::endl;
			std::wcout << "Wather/Total Area: " << info->getWater(i) / (double)info->getTotalArea(i) << std::endl;
			std::wcout << "Forest/Total Area: " << info->getForest(i) / (double)info->getTotalArea(i) << std::endl;
			std::wcout << "Builtup Area/Total Area: " << info->getBuiltupArea(i) / (double)info->getTotalArea(i) << std::endl << std::endl;
		}
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::townByTotalArea()
{
	int year = readYear();
	Order order = readOrder();
	auto towns = manager->getTownsByArea(year, order);
	std::cout << std::endl << "Towns by Total Area" << std::endl << std::endl;

	int i = 0;
	for each (auto ti in towns)
	{
		for each (auto t in ti->accessData())
		{
			std::wcout << i + 1 << ". " << order * ti->getKey() << " - " << t->getName()
				<< "  (Dist: " << t->getDistrict().getName() << ", Reg: " << t->getDistrict().getRegion()->getName() << ")" << std::endl;
		}
		if (++i >= numberOfLines)
			break;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::townByBuiltupAreaIncrease()
{
	int firstYear = readYear(Year::ONE);
	int secondYear = readYear(Year::TWO);
	Order order = readOrder();
	auto towns = manager->townsBuiltupAreaIncrease(firstYear, secondYear, order);
	std::cout << std::endl << "Towns by Builtup Area Increase" << std::endl << std::endl;

	int i = 0;
	for each (auto ti in towns)
	{
		for each (auto t in ti->accessData())
		{
			std::wcout << i + 1 << ". " << order * ti->getKey() << " - " << t->getName()
				<< "  (Dist: " << t->getDistrict().getName() << ", Reg: " << t->getDistrict().getRegion()->getName() << ")" << std::endl;
		}
		if (++i >= numberOfLines)
			break;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::townsByArableLandRatioDifference()
{
	int firstYear = readYear(Year::ONE);
	int secondYear = readYear(Year::TWO);
	Order order = readOrder();
	auto towns = manager->townsArableLandRatioDifference(firstYear, secondYear, order);
	std::cout << std::endl << "Towns by Arable Land Ratio Difference (Arable Land/Total Area)" << std::endl << std::endl;

	int i = 0;
	for each (auto ti in towns)
	{
		for each (auto t in ti->accessData())
		{
			std::wcout << i + 1 << ". " << order * ti->getKey() << " - " << t->getName()
				<< "  (Dist: " << t->getDistrict().getName() << ", Reg: " << t->getDistrict().getRegion()->getName() << ")" << std::endl;
		}
		if (++i >= numberOfLines)
			break;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::districtByOchard()
{
	int year = readYear();
	Extreme extreme = readExtreme();
	auto districts = manager->districtByOchard(year, extreme);
	std::cout << std::endl << "District by Ochard" << std::endl << std::endl;

	for each (auto d in districts)
	{
		std::wcout << d->getOchard(year)
			<< " - " << d->getName() << "  (Region: " << d->getRegion()->getName() << ")" << std::endl;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::districtByArableLandRatio()
{
	int year = readYear();
	Extreme extreme = readExtreme();
	auto districts = manager->districtByArableOchardRatio(year, extreme);
	std::cout << std::endl << "District by Arable Land Ratio (Arabe Land/Total Area)" << std::endl << std::endl;

	for each (auto d in districts)
	{
		std::wcout << ((double)d->getOchard(year) == 0 ? 0 : d->getArableLand(year) / (double)d->getOchard(year))
			<< " - " << d->getName() << "  (Region: " << d->getRegion()->getName() << ")" << std::endl;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::districtByForestRatio()
{
	int year = readYear();
	Extreme extreme = readExtreme();
	auto districts = manager->districtByForestRatio(year, extreme);
	std::cout << std::endl << "District by Forest Ratio (Forest/Total Area)" << std::endl << std::endl;

	for each (auto d in districts)
	{
		std::wcout << d->getForest(year) / (double)d->getTotalArea(year)
			<< " - " << d->getName() << "  (Region: " << d->getRegion()->getName() << ")" << std::endl;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::districtByOchardRatioDifference()
{
	int firstYear = readYear(Year::ONE);
	int secondYear = readYear(Year::TWO);
	Order order = readOrder();
	auto districts = manager->districtsOchardRatioDifference(firstYear, secondYear, order);
	std::cout << std::endl << "District by Ochard Ratio Difference (Ochard/Total Area)" << std::endl << std::endl;

	int i = 0;
	for each (auto ti in districts)
	{
		for each (auto d in ti->accessData())
		{
			std::wcout << i + 1 << ". " << order * ti->getKey()
				<< " - " << d->getName() << "  (Region: " << d->getRegion()->getName() << ")" << std::endl;
		}
		if (++i >= numberOfLines)
			break;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::districtByArableLandRatioDifference()
{
	int firstYear = readYear(Year::ONE);
	int secondYear = readYear(Year::TWO);
	Order order = readOrder();
	auto districts = manager->districtsArableLandRatioDifference(firstYear, secondYear, order);
	std::cout << std::endl << "District by Arable Land Ratio Difference (Arable Land/Total Area)" << std::endl << std::endl;

	int i = 0;
	for each (auto ti in districts)
	{
		for each (auto d in ti->accessData())
		{
			std::wcout << i + 1 << ". " << order * ti->getKey()
				<< " - " << d->getName() << "  (Region: " << d->getRegion()->getName() << ")" << std::endl;
		}
		if (++i >= numberOfLines)
			break;
	}
	std::cin.ignore();
	std::cin.get();
}

void CLI::districtByForestRatioDifference()
{
	int firstYear = readYear(Year::ONE);
	int secondYear = readYear(Year::TWO);
	Order order = readOrder();
	auto districts = manager->districtsForestRatioDifference(firstYear, secondYear, order);
	std::cout << std::endl << "District by Forest Ratio Difference (Forest/Total Area)" << std::endl << std::endl;

	int i = 0;
	for each (auto ti in districts)
	{
		for each (auto d in ti->accessData())
		{
			std::wcout << i + 1 << ". " << order * ti->getKey()
				<< " - " << d->getName() << "  (Region: " << d->getRegion()->getName() << ")" << std::endl;
		}
		if (++i >= numberOfLines)
			break;
	}
	std::cin.ignore();
	std::cin.get();
}


int CLI::readYear(Year y)
{
	std::string preposition = "";
	switch (y)
	{
	case FROM:
		preposition = " from";
		break;
	case TO:
		preposition = " to";
		break;
	case ONE:
		preposition = " 1";
		break;
	case TWO:
		preposition = " 2";
		break;
	default:
		break;
	}

	std::cout << "Enter year" << preposition << ": ";
	int year;
	std::cin >> year;
	return year;
}

Order CLI::readOrder()
{
	std::cout << "In order (Ascending - 1, Descending - 2): ";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		return Order::ASC;
	}
	else {
		return Order::DESC;
	}
}

Extreme CLI::readExtreme()
{
	std::cout << "Extreme (MIN - 1, MAX - 2): ";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		return Extreme::MIN;
	}
	else {
		return Extreme::MAX;
	}
}

CLI::CLI()
{
	manager = new Manager();

	std::cout << "Loading Regions..." << std::endl << std::endl;
	manager->loadInfo();
	system("cls");
}

CLI::~CLI()
{
	delete manager;
}

void CLI::run()
{
	bool running = true;
	do
	{
		int choice = printMenu();

		switch (choice)
		{
		case 1: townByName(); break;
		case 2: townByTotalArea(); break;
		case 3: townByBuiltupAreaIncrease(); break;
		case 4: townsByArableLandRatioDifference(); break;
		case 5: districtByOchard(); break;
		case 6: districtByArableLandRatio(); break;
		case 7: districtByForestRatio(); break;
		case 8: districtByOchardRatioDifference(); break;
		case 9: districtByArableLandRatioDifference(); break;
		case 10: districtByForestRatioDifference(); break;
		case 11: running = false; break;
		}
		system("cls");

	} while (running);
}
