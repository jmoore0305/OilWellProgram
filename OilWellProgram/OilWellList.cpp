#include "OilWellList.h"


OilWellList::OilWellList(OilFieldDataParser* parser)
{
    bool moreWells = true;

    wellCount = 0;

    int sensorCount = 0;

    char** senArray;

    while (moreWells)
    {

        moreWells = parser->getWellData(wellID, wellOptr, &sensorCount, &senArray);

        if (moreWells)
        {
            OilWell* well = new OilWell(wellID, wellOptr, sensorCount, senArray);
            this->addWell(well);
        }

    }

}


void OilWellList::loadWellIDs()
{
    wellIDList.clear();

    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);
        wellIDList.push_back(well->getWellId());
    }
}

void OilWellList::loadWellNames()
{
    wellNamesList.clear();

    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);
        wellNamesList.push_back(well->getOptrName());
    }
}

bool OilWellList::searchOilWellList(string id)
{
    bool found = false;

    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);

        if (well->getWellId() == id)
        {
            found = true;
            well->setDisplayValue(found);
        }
        
    }

    return found;
}


bool OilWellList::addWell(OilWell* w)
{
    wellList.push_back(w);
    wellCount++;
    return true;
}


vector<OilWell*> OilWellList::getList()
{
    return wellList;
}

OilWell* OilWellList::getWell(int i)
{
    return wellList.at(i);
}

int OilWellList::getWellCount()
{
    return wellCount;
}


void OilWellList::displayWellNamesAndIDs()
{
    for (int i = 0; i < wellIDList.size(); i++)
    {
        cout << "name: " << wellNamesList.at(i) << endl;
        cout << "id: " << wellIDList.at(i) << endl;
        cout << "displaying sensor list for well..." << endl;

        OilWell* well = wellList.at(i);
        well->displaySensorArray();

        cout << endl;
    }
    cout << endl << endl;

}





