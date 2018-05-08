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
	//if (arableLand != NULL) { delete arableLand; }//orna poda
	//if (hopGarden != NULL) { delete hopGarden; }//chmelnica
	//if (vineyard != NULL) { delete vineyard; }//vinica
	//if (garden != NULL) { delete garden; }//zahrada
	//if (ochard != NULL) { delete ochard; }//ovocny sad
	//if (lawn != NULL) { delete lawn; }//travnik

	//if (forest != NULL) { delete forest; }//les
	//if (water != NULL) { delete water; }//voda
	//if (builtupArea != NULL) { delete builtupArea; }//zastanena plocha
	//if (theRest != NULL) { delete theRest; }//ostatna plocha

	if (arableLand) { delete arableLand; }//orna poda
	if (hopGarden) { delete hopGarden; }//chmelnica
	if (vineyard) { delete vineyard; }//vinica
	if (garden) { delete garden; }//zahrada
	if (ochard) { delete ochard; }//ovocny sad
	if (lawn) { delete lawn; }//travnik

	if (forest) { delete forest; }//les
	if (water) { delete water; }//voda
	if (builtupArea) { delete builtupArea; }//zastanena plocha
	if (theRest) { delete theRest; }//ostatna plocha
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
