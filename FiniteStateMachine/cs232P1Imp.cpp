/******************************************************************************
*
*   Programmer: Jeremiah Ibarra
*   Instructor: Professor Streller
*   Course: CS232
*   Date: 03.08.2024
*   Program Name: CS232_P1_ibarra
*   Program File: cs232P1Imp.cpp
*   Input Files: none
*   Output Files: none
*   Purpose: a finite state machine that will simulate the behavior of a lock when five characters are entered
*
******************************************************************************/



#include <iostream>
#include <string>
#include<fstream>
#include<cctype>
#include<ctype.h>

using namespace std;


#include "cs232P1Header.h"
#include "pair.h"
#include "table.h"


int map(const Pair<STATE, EVENT>p) {

    return (int)p.first * 5 + (int)p.second;
}


STATE convertSTATE(string str) {

    if (str == "nke")
    {
        return nke;
    }
    else if (str == "ok1")
    {
        return ok1;
    }
    else if (str == "ok2")
    {
        return ok2;
    }
    else if (str == "ok3")
    {
        return ok3;
    }
    else if (str == "fa1")
    {
        return fa1;
    }
    else if (str == "fa2")
    {
        return fa2;
    }
    else if (str == "fa3")
    {
        return fa3;
    }
}

EVENT convertEVENT(const string& str) {

    if (str == "A")
    {
        return A;
    }
    else if (str == "B")
    {
        return B;
    }
    else if (str == "C")
    {
        return C;
    }
    else if (str == "D")
    {
        return D;
    }
    else if (str == "E")
    {
        return E;
    }
    else
    {
        cout << "Error converting EVENT: " << str << endl;
        return F;
    }

}

void transition(ifstream& transitionFile, Table<Pair<STATE, EVENT>, STATE> &table) //read transitiion
{
    string temp1, temp2;
    Pair<STATE, EVENT> pair;
    STATE s1, s2;
    Pair <Pair<STATE, EVENT>, STATE> transitionPair;

    transitionFile >> ws;

    if (transitionFile.peek() == 'A') // if first char is an 'A' get entire line
    {
        getline(transitionFile, temp1);
    }
    while (transitionFile >> temp1) // 
    {
        s1 = convertSTATE(temp1);

        for (int i = 0; i < 5; i++)
        {

            transitionFile >> temp2;
            s2 = convertSTATE(temp2);

            pair = makePair(s1, (EVENT)i);
            transitionPair = makePair(pair, s2);
            table.insert(transitionPair);

        }

    }

}

void action(ifstream& actionFile, Table<Pair<STATE, EVENT>, string> &action) //read action
{
    string temp, temp2 = " ", emptyString = "";
    STATE s1;
    EVENT e1;
    Pair <STATE, EVENT> pair;

    actionFile >> ws;

    if (actionFile.peek() == 'A')
    {
        getline(actionFile, temp);
    }
    while (actionFile >> temp)
    {

        actionFile.ignore(2);
        s1 = convertSTATE(temp);
        for (int i = 0; i < 5; i++)
        {
            pair = makePair(s1, (EVENT)(i));
            if (actionFile.peek() == '\n')
            {
                actionFile >> ws;
                break;
            }
            if (isspace(actionFile.peek()))
            {
                actionFile.ignore(2);
            }
            else
            {

                actionFile >> temp2;
                action.insert(makePair(pair, temp2));
                actionFile.ignore(2);
            }

        }
    }
        actionFile.clear();
}