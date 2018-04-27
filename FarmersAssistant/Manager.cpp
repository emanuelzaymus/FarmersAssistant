#include "Manager.h"
#include "structures\heap_monitor.h"



Manager::Manager()
{
	fh = new FileHandler();

	fh->readRegionUTF8("data/Uzemne_clenenie_SR_ZA_changedUTF8.csv");
	//fh->readPopulationUTF8("data/Obyvatelstvo_podla_trvaleho_pobytu_changedUTF8.csv");
	//fh->readLandUTF8("data/Vymera_uzemia_vyuzitie_pody_changedUTF8.csv");
}


Manager::~Manager()
{
}
