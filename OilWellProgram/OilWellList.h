#pragma once
#include "OilWell.h"
#include "OilFieldDataParser.h"
#include <string>

using namespace std;

class OilWellList
{
private:
	char wellID[32];
	char wellOptr[64];
	vector<OilWell*> wellList;
	vector<char*> wellIDList;
	vector<char*> wellNamesList;
	int wellCount;
public:
	OilWellList(OilFieldDataParser*);
	void loadWellIDs();
	void loadWellNames();
	bool searchOilWellList(string);
	void displayWellNamesAndIDs();
	bool addWell(OilWell*);
	vector<OilWell*> getList();
	OilWell* getWell(int);
	int getWellCount();
	
		
};

