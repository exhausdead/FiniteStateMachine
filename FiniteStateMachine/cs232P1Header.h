/******************************************************************************
*
*   Programmer: Jeremiah Ibarra
*   Instructor: Professor Streller
*   Course: CS232
*   Date: 03.08.2024
*   Program Name: CS232_P1_ibarra
*   Program File: cs232P1Header.h
*   Input Files: none
*   Output Files: none
*   Purpose: a finite state machine that will simulate the behavior of a lock when five characters are entered
*
******************************************************************************/


#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<cctype>
#include<ctype.h>



using namespace std;


#include "cs232P1Header.h"
#include "pair.h"
#include "table.h"

#include "tableSpecificOps1.h"

#ifndef  CS_232_P1_HEADER
#define  CS_232_P1_HEADER
#include "pair.h"



typedef enum STATE
{
	nke, ok1, ok2, ok3, fa1, fa2, fa3
} aState;

typedef enum EVENT
{
	A, B, C, D, E, F
} anEvent;

/******************************************************************************
*   Function Name: map
*	Purpose: Properly maps table
*   Parameters: Pair
*		Input: Pair
*		Output: Integer
*	Return Value: Integer

******************************************************************************/
int map(const Pair<STATE, EVENT>p);


/******************************************************************************
*   Function Name: convertSTATE
*	Purpose: converts a string to a STATE
*   Parameters: string
*		Input: string
*		Output: STATE
*	Return Value: STATE

******************************************************************************/
STATE convertSTATE(string str);


/******************************************************************************
*	Function Name: convertEVENT
*	Purpose: converts a string to an EVENT
*   Parameters: string
*		Input: string
*		Output: EVENT
*	Return Value: EVENT

******************************************************************************/
EVENT convertEVENT(const string& str);



/******************************************************************************
*   Function Name: transition
*	Purpose: reads transition file into a table
*   Parameters: ifstream, Table, STATE
*		Input:  ifstream, Table, STATE
*		Output: none
*	Return Value: void

******************************************************************************/
void transition(ifstream& transitionFile, Table<Pair<STATE, EVENT>, STATE>& table);


/******************************************************************************
*   Function Name: action
*	Purpose: reads action file into a table
*   Parameters: ifstream, Table, string
*		Input:  ifstream, Table, string
*		Output: none
*	Return Value: void

******************************************************************************/
void action(ifstream& transitionFile, Table<Pair<STATE, EVENT>, string>& action);


#endif