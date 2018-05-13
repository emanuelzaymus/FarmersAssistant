#pragma once

#include "structures\heap_monitor.h"
#include "structures\array\array.h"

class PopulationInfo
{
public:
	class CountIn5Years
	{
	private:
		int men;
		int women;
	public:
		CountIn5Years(int men, int women) : men(men), women(women) {}
		int getBoth() { return men + women; }
		int getMen() { return men; }
		int getWomen() { return women; }
	};

private:
	structures::Array<CountIn5Years*>* population = new structures::Array<CountIn5Years*>(POPUL_GROUPS);
	int totalMen;
	int totalWomen;

public:
	static const int POPUL_GROUPS = 21;
	
	PopulationInfo();
	~PopulationInfo();

	void addCountIn5Years(int firstYearDiv5, int men, int women);
};

