#pragma once

#include "structures\heap_monitor.h"

#include "Manager.h"

enum Year
{
	FROM,
	TO,
	ONE,
	TWO,
	NONE
};

class CLI
{
	Manager* manager;
	const int numberOfLines = 60;

	int printMenu();

	void townByName();
	void townByTotalArea();
	void townByBuiltupAreaIncrease();
	void townsByArableLandRatioDifference();
	void districtByOchard();
	void districtByArableLandRatio();
	void districtByForestRatio();
	void districtByOchardRatioDifference();
	void districtByArableLandRatioDifference();
	void districtByForestRatioDifference();
	
	int readYear(Year y = Year::NONE);
	Order readOrder();
	Extreme readExtreme();

	std::wstring read();

public:
	CLI();
	~CLI();

	void run();
};

