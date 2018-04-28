#include "Manager.h"
#include "structures\heap_monitor.h"



Manager::Manager()
{
	fh = new FileHandler();
}


Manager::~Manager()
{
	delete fh;

	while (!regions->isEmpty())
		delete regions->removeAt(regions->size() - 1);
	delete regions;
}

void Manager::loadInfo()
{
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_BA_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_BB_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_KE_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_NR_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_PO_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_TN_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_TT_changedUTF8.csv"));
	//regions->add(fh->readRegionUTF8("data/Uzemne_clenenie_SR_ZA_changedUTF8.csv"));

	//fh->readPopulationUTF8("data/Obyvatelstvo_podla_trvaleho_pobytu_changedUTF8.csv");

	fh->readLandUTF8("data/Vymera_uzemia_vyuzitie_pody_changedUTF8.csv");
}
