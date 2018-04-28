#include "PopulationInfo.h"

#include "structures\heap_monitor.h"


PopulationInfo::PopulationInfo()
{
}


PopulationInfo::~PopulationInfo()
{
	for (size_t i = 0; i < population->size(); i++)
	{
		if ((*population)[i] != nullptr)
			delete (*population)[i];
	}
	delete population;
}

void PopulationInfo::addCountIn5Years(int firstYearDiv5, int men, int women)
{
	(*population)[firstYearDiv5] = new PopulationInfo::CountIn5Years(men, women);
	totalBoth += men + women;
	totalMen += men;
	totalWomen += women;
}
