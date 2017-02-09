// NasaPhoneNumber.cpp : Defines the entry point for the console application.
//
//libraries
#include "stdafx.h"
#include<iostream>
#include<string>
#include "NumberGenerator.h"

using namespace std;

int main()
{
	int end = 0;//boolean
	string ended;//confirm string
	while (end == 0)//loop
	{
		NumberGenerator();//call to object
		cout << "End? y or n : ";//ask to end
		cin >> ended;
		//input validation
		while (ended != "y" && ended != "n")
		{
			cout << "Enter 'y' or 'n' : ";
			cin >> ended;
		}
		//if end set to 1 to break
		if (ended == "y")
		{
			end = 1;
		}
	}
    return 0;
}

