/******************************************************************************
*
*   Programmer: Jeremiah Ibarra
*   Instructor: Professor Streller
*   Course: CS232
*   Date: 03.08.2024
*   Program Name: CS232_P1_ibarra
*   Program File: cs232P1Driver.cpp
*   Input Files: transition_table.txt action_table.txt
*   Output Files: none
*   Purpose: a finite state machine that will simulate the behavior of a lock when five characters are entered
*
******************************************************************************/


using namespace std;
#include "cs232P1Header.h"


int main()
{
    
    string temp;
    string work;
    string combo;
    string thing;
    EVENT even;
    STATE st;


    Table <Pair <STATE, EVENT>, STATE> transitionTable(35, map);
    Table <Pair <STATE, EVENT>, string> actionTable(35, map);

   
    ifstream tfile;
    string taddress;
    cout << "Enter Address of File you want to open or enter in transition_table.txt for pre saved file: ";
    getline(cin, taddress);
    tfile.open(taddress);
    if (!tfile.is_open())
    {
        cout << "No file to open. Rerun program to try again.";
        exit(0);
        tfile.clear();
    }

        transition(tfile, transitionTable);
        //transitionTable.print(); //for debugging
        tfile.close();

        
       
        ifstream afile;
        string aaddress;
        cout << "Enter Address of File you want to open or enter in action_table.txt for pre saved file: ";
        getline(cin, aaddress);
        afile.open(aaddress);
        if (!afile.is_open())
        {
            cout << "No file to open. Rerun program to try again.";
            exit(0);
            afile.clear();
        }

        action(afile, actionTable);
        //actionTable.print(); //for debugging
        afile.close();
        
    
        while (work != "unlock")
        {
            cout << "enter PIN (A,B,C,D or E): ";
            cin >> combo;
            st = nke;

            if (size(combo) != 4)
            {
                cout << "invalid input";
            }

            else
            {
                for (int i = 0; i < 4; i++)
                {
                    combo[i] = toupper(combo[i]);
                    if (combo[i] < 'A' || combo[i] > 'E')
                    {
                        cout << "incorrect PIN..." << endl;
                        work = "error";
                    }
                }
                if (work != "error")
                {
                    for (int i = 0; i < 4; i++)
                    {
                        thing = combo[i];
                        even = convertEVENT(thing);

                        work = actionTable.lookUp(makePair(st, even));
                        cout << work << endl;
                        st = transitionTable.lookUp(makePair(st, even));
                    }

                }
            }
        }
    

  return (0);

}
