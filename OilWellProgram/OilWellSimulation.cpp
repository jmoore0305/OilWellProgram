#define _CRT_SECURE_NO_WARNINGS
#include "OilWellSimulation.h"




OilWellSimulation::OilWellSimulation()
{
     
	 model = new Model();
	 view = new View(model);

     tStruct = {
        0,
        0,
        0,
        0,
     };

     done = false;  // while loop flag
     hit = 0;     // key hit flag
     ch = ' ';     // character key which was hit
     char response = ' ';

     _ftime(&tStruct);	// Get start time
     thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
     outputTime = thisTime + 5.0; // Set next 5 second interval time

	 runSimulation();
}


void OilWellSimulation::runSimulation()
{


    do
    {
        cout << endl << endl;
        cout << "Welcome to the Oil Well and Sensor Monitoring Program!" << endl << endl;
        cout << "Press 8 to enter the menu and 2 to exit the program" << endl << endl << endl;
        cin >> response;

    } while (response != '8' && response != '2');

    if (response == '8')
        view->printMenu();
    else
        exit(1);

    while (!done)     // Start an eternal loop
    {
        _ftime(&tStruct);    // Get the current time
        thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if (thisTime >= outputTime)
        {
            cout << "Press 8 to enter the menu and 2 to exit the program" << endl << endl << endl;
            model->update();
            view->printReport();
            outputTime += 5.0; // Set time for next 5 second interval
        }
        hit = _kbhit(); //See if a key has been pressed

        if (hit)
        {
            ch = _getch();	// Get the key pressed
            // Now you can check ch to see what key was pressed.
        }

        if (ch == '8')
            view->printMenu();

        if (ch == '2')
            exit(1);

    }


}

