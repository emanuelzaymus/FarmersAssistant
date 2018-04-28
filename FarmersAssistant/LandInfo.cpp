#include "LandInfo.h"
#include "structures\heap_monitor.h"



LandInfo::LandInfo()
{
	//arableLand = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//hopGarden = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//vineyard = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//garden = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//ochard = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//lawn = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);

	//forest = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//water = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//builtupArea = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
	//theRest = new structures::Array<int>(MAX_YEAR - MIN_YEAR + 1);
}


LandInfo::~LandInfo()
{
	delete arableLand;//orna poda
	delete hopGarden;//chmelnica
	delete vineyard;//vinica
	delete garden;//zahrada
	delete ochard;//ovocny sad
	delete lawn;//travnik

	delete forest;//les
	delete water;//les
	delete builtupArea;//zastanena plocha
	delete theRest;//ostatna plocha
}

int LandInfo::getTotalAreat(int year)
{
	return getTotalAgriculturalArea(year) + getTotalNonagriculturalArea(year);
}

int LandInfo::getTotalAgriculturalArea(int year)
{
	return getArableLand(year) + getHopGarden(year) + getVineyard(year) + getGarden(year) + getOchard(year) + getLawn(year);
}

int LandInfo::getTotalNonagriculturalArea(int year)
{
	return getForest(year) + getWater(year) + getBuiltupArea(year) + getTheRest(year);
}
