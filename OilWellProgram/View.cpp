#include "View.h"

using namespace std;

View::View(Model* theModel)
{
    model = theModel;
    display = new Display(theModel);
}

void View::printMenu()
{
    bool found = false;
    string id = "";
    string ans = "";
    bool over = false;
    string name = " ";
    bool done = false;
    string theAnswer = " ";
    bool finished = false;
    string imDone = " ";
    OilWellList* wellList = model->getWellList();


    do
    {
        cout << endl;

        display->displayWellNamesAndIDs();

        cout << "Enter the Well ID corresponding to the well you'd like displayed e.g. 12-1234 ... Include the dash." << endl;
        cin >> id;
        cout << endl;


        found = wellList->searchOilWellList(id);

        if (found)
            cout << "Success! Your well selection has been added to the list... " << endl << endl;
        else
            cout << "Well not found, please try again... " << endl << endl;


        cout << "Are you done selecting well? Press 5 to end and any other key to continue..." << endl;
        cin >> ans;

        if (ans == "5")
            over = true;

    } while (!over);


  
    found = false;

    do
    {
        

        for (int i = 0; i < wellList->getWellCount(); i++)
        {
            OilWell* well = wellList->getWell(i);

            if (well->getDisplayValue() == true)
            {
               
                cout << "One of your selected wells for display is..." << endl << endl;

                well->displayData();

                char** senArray = well->getSenArray();

                cout << "The sensors for this well are..." << endl;

                for (int i = 0; i < well->getSensorListSize(); i++)
                {
                    cout << senArray[i] << endl;
                }
                cout << endl;

                do
                {

                    cout << "Enter the name of the sensor you want displayed" << endl;
                    cin >> name;
                    found = well->searchSensorList(name);

                    if (found)
                        cout << "Success! Your sensor will be displayed when you leave this menu" << endl;
                    else
                        cout << "Your sensor was not found" << endl;

                    cout << "Would you like to try again? Enter 1 for no and anything else for yes" << endl;

                    cin >> imDone;

                    if (imDone == "1")
                        finished = true;

                } while (!finished);


            }
        }

        cout << "Are you done selecting sensors for the wells? Enter 3 to exit and anything else to continue to restart your selection process..." << endl;
        cin >> theAnswer;

        if (theAnswer == "3")
            done = true;
        
    } while (!done);
}

void View::printReport()
{
    
    cout << endl << endl;
    cout << "printing report..." << endl;
    display->displayActivelySelectedWellData();
    display->displayActivelySelectedSensorData();
}
