#pragma once

#include "structures\heap_monitor.h"
#include "structures\array\array.h"

enum Land
{
	ArableLand,
	HopGarden,
	Vineyard,
	Garden,
	Ochard,
	Lawn,

	Forest,
	Wather,
	BuiltupArea,
	TheRest
};

class LandInfo
{
private:
	structures::Array<int>* arableLand;//orna poda
	structures::Array<int>* hopGarden;//chmelnica
	structures::Array<int>* vineyard;//vinica
	structures::Array<int>* garden;//zahrada
	structures::Array<int>* ochard;//ovocny sad
	structures::Array<int>* lawn;//travnik

	structures::Array<int>* forest;//les
	structures::Array<int>* water;//les
	structures::Array<int>* builtupArea;//zastanena plocha
	structures::Array<int>* theRest;//ostatna plocha

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

	int getArableLand(int year) { return (*arableLand)[year - MIN_YEAR]; }
	int getHopGarden(int year) { return (*hopGarden)[year - MIN_YEAR]; }
	int getVineyard(int year) { return (*vineyard)[year - MIN_YEAR]; }
	int getGarden(int year) { return (*garden)[year - MIN_YEAR]; }
	int getOchard(int year) { return (*ochard)[year - MIN_YEAR]; }
	int getLawn(int year) { return (*lawn)[year - MIN_YEAR]; }
	int getForest(int year) { return (*forest)[year - MIN_YEAR]; }
	int getWater(int year) { return (*water)[year - MIN_YEAR]; }
	int getBuiltupArea(int year) { return (*builtupArea)[year - MIN_YEAR]; }
	int getTheRest(int year) { return (*theRest)[year - MIN_YEAR]; }

	int getTotalAreat(int year);
	int getTotalAgriculturalArea(int year);
	int getTotalNonagriculturalArea(int year);
};

