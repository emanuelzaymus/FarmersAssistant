#include "LandInfo.h"
#include "structures\heap_monitor.h"



LandInfo::LandInfo()
{
}


LandInfo::~LandInfo()
{
	if (arableLand != nullptr) { delete arableLand; }//orna poda
	if (hopGarden != nullptr) { delete hopGarden; }//chmelnica
	if (vineyard != nullptr) { delete vineyard; }//vinica
	if (garden != nullptr) { delete garden; }//zahrada
	if (ochard != nullptr) { delete ochard; }//ovocny sad
	if (lawn != nullptr) { delete lawn; }//travnik

	if (forest != nullptr) { delete forest; }//les
	if (water != nullptr) { delete water; }//voda
	if (builtupArea != nullptr) { delete builtupArea; }//zastanena plocha
	if (theRest != nullptr) { delete theRest; }//ostatna plocha
}

int LandInfo::getTotalArea(int year)
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
