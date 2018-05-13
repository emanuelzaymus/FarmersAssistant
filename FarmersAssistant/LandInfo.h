#pragma once

#include "structures\heap_monitor.h"
#include "structures\array\array.h"


class LandInfo
{
private:
	structures::Array<int>* arableLand = nullptr;//orna poda
	structures::Array<int>* hopGarden = nullptr;//chmelnica
	structures::Array<int>* vineyard = nullptr;//vinica
	structures::Array<int>* garden = nullptr;//zahrada
	structures::Array<int>* ochard = nullptr;//ovocny sad
	structures::Array<int>* lawn = nullptr;//travnik

	structures::Array<int>* forest = nullptr;//les
	structures::Array<int>* water = nullptr;//voda
	structures::Array<int>* builtupArea = nullptr;//zastanena plocha
	structures::Array<int>* theRest = nullptr;//ostatna plocha

public:
	static const int MIN_YEAR = 1996;
	static const int MAX_YEAR = 2017;

	LandInfo();
	~LandInfo();

	void setArableLand(structures::Array<int>* arr) { arableLand = arr; }
	void setHopGarden(structures::Array<int>* arr) { hopGarden = arr; }
	void setVineyard(structures::Array<int>* arr) { vineyard = arr; }
	void setGarden(structures::Array<int>* arr) { garden = arr; }
	void setOchard(structures::Array<int>* arr) { ochard = arr; }
	void setLawn(structures::Array<int>* arr) { lawn = arr; }
	void setForest(structures::Array<int>* arr) { forest = arr; }
	void setWater(structures::Array<int>* arr) { water = arr; }
	void setBuiltupArea(structures::Array<int>* arr) { builtupArea = arr; }
	void setTheRest(structures::Array<int>* arr) { theRest = arr; }

	int getArableLand(int year) { return arableLand == nullptr ? 0 : (*arableLand)[year - MIN_YEAR]; }
	int getHopGarden(int year) { return hopGarden == nullptr ? 0 : (*hopGarden)[year - MIN_YEAR]; }
	int getVineyard(int year) { return vineyard == nullptr ? 0 : (*vineyard)[year - MIN_YEAR]; }
	int getGarden(int year) { return garden == nullptr ? 0 : (*garden)[year - MIN_YEAR]; }
	int getOchard(int year) { return ochard == nullptr ? 0 : (*ochard)[year - MIN_YEAR]; }
	int getLawn(int year) { return lawn == nullptr ? 0 : (*lawn)[year - MIN_YEAR]; }
	int getForest(int year) { return forest == nullptr ? 0 : (*forest)[year - MIN_YEAR]; }
	int getWater(int year) { return water == nullptr ? 0 : (*water)[year - MIN_YEAR]; }
	int getBuiltupArea(int year) { return builtupArea == nullptr ? 0 : (*builtupArea)[year - MIN_YEAR]; }
	int getTheRest(int year) { return theRest == nullptr ? 0 : (*theRest)[year - MIN_YEAR]; }

	int getTotalArea(int year);
	int getTotalAgriculturalArea(int year);
	int getTotalNonagriculturalArea(int year);
};

