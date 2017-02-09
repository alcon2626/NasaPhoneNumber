#include "stdafx.h"
#include "NumberGenerator.h"
#include<random>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <sstream>

using namespace std;

//display function
void Display(int a, int b, int c, int d, int e, int f, int g, int h, int j, int k) {
	//debug display
	cout << "(";
	cout << a << b << c;
	cout << ")";
	cout << d << e << f;
	cout << " - ";
    cout << g << h << j << k;
}
//boolean repeated values
bool repeated(int e, int f, int g, int h, int j, int k,
	          int p, int q, int r, int s, int t, int v) 
{
	stringstream ss, tt;
	ss << e;
	ss << f;
	ss << g;
	ss << h;
	ss << j;
	ss << k;
	tt << p;
	tt << q;
	tt << r;
	tt << s;
	tt << t;
	tt << v;
	int result_1;
	int result_2;
	ss >> result_1;
	tt >> result_2;
	if (result_1 == result_2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

NumberGenerator::NumberGenerator()
{
	/*In order to provide security, the last 6 digits of the phone number must add to 33.
	If the fourth number is odd the fifth number must be even. Likewise, if the fourth number
	is even the fifth number must be odd. Write a phone number generator that asks for the first four digits.
	The computer must generate a list of all possible phone numbers that meet the new security rule,
	and display them as follows*/
	//(xxx)xxx-xxxx
	int Digits[10];
	//set all digits to 0
	for (int i = 0; i < 10; i++)
	{
		Digits[i] = 0;
	}
	//display calling funct
	cout << endl;
	Display(Digits[0], Digits[1], Digits[2], Digits[3], 
	    Digits[4], Digits[5], Digits[6], Digits[7], Digits[8], Digits[9]);
	//enter first 4 digits
	cout << "\nEnter the first 4 digits separated by spaces: ";
	cin >> Digits[0] >> Digits[1] >> Digits[2] >> Digits[3];
	//debug display
	cout << endl;
	Display(Digits[0], Digits[1], Digits[2], Digits[3],
		Digits[4], Digits[5], Digits[6], Digits[7], Digits[8], Digits[9]);
	//chech the 4th digit even or odd
	if (Digits[3] % 2 == 0) 
	{
		int X;
		cout << endl;
		cout << "Forth digit " << Digits[3] << " is even." << endl;
		X = rand() % 10;
		cout << "X:" << X << endl;
		while (X % 2 == 0)
		{
			X = rand() % 10;
		}
		if (X % 2 != 0)
		{
			Digits[4] = X;
		}
	}
	else
	{
		cout << endl;
		cout << "Forth digit " << Digits[3] << " is odd." << endl;
		int X;
		X = rand() % 10;
		while (X % 2 != 0)
		{
			X = rand() % 10;
		}
		if (X % 2 == 0)
		{
			Digits[4] = X;
		}
	}
	//debug display
	Display(Digits[0], Digits[1], Digits[2], Digits[3],
		Digits[4], Digits[5], Digits[6], Digits[7], Digits[8], Digits[9]);
	//call until all posible combinations
	bool found = false;
	cout << endl;
	vector<int> found_ed;
	int count = 0;//for me to keep track
	//two dimentional array
	int two_dimention[900][10];
	//set to 0
	for (int i = 0; i < 900; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			two_dimention[i][j] = 0;
		}
	}
	//commence
	while (found == false)
	{
		bool yes = false;
		//now logic to add all numbers to 33
		while (Digits[4] + Digits[5] + Digits[6] + Digits[7] + Digits[8] + Digits[9] != 33)
		{
			Digits[5] = rand() % 10;
			Digits[6] = rand() % 10;
			Digits[7] = rand() % 10;
			Digits[8] = rand() % 10;
			Digits[9] = rand() % 10;
		}
		yes = true;
		//store in 2 dimentional array
		for (int i = count; i < count+1; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				two_dimention[i][j] = Digits[j];
			}
		}
		//creat new vectors everytime one is found
		vector<int> a;
		while (yes == true)
		{
			a.push_back(Digits[5]);
			a.push_back(Digits[6]);
			a.push_back(Digits[7]);
			a.push_back(Digits[8]);
			a.push_back(Digits[9]);
			yes = false;
		}
		//need to repeat over and over now
		while (a[0] == Digits[5] || a[1] == Digits[6] || a[2] == Digits[7] || a[2] == Digits[8]|| a[4] == Digits[9])
		{
			Digits[5] = rand() % 10;
			Digits[6] = rand() % 10;
			Digits[7] = rand() % 10;
			Digits[8] = rand() % 10;
			Digits[9] = rand() % 10;
		}
		//reuse
		a.clear();
		count++;
		//display
		if (count > 899)
		{
			found = true;
			//check values
			for (int  i = 0; i < 900; i++)
			{
				for (int count = 0; count < 900; count++)
				{
					bool yes = repeated(two_dimention[i][4], two_dimention[i][5], two_dimention[i][6], two_dimention[i][7],
						two_dimention[i][8], two_dimention[i][9], two_dimention[count][4], two_dimention[count][5], two_dimention[count][6], two_dimention[count][7],
						two_dimention[count][8], two_dimention[count][9]);
					if (i == count)
					{

					}
					else
					{
						if (yes == true)
						{
							cout << "Repeated: " << count << " and " << i << endl;
						}
					}
				}
			}
			cout << "Possible combinations" << endl;
			//display
			for (int i = 0; i < 900; i++)
			{
				Display(two_dimention[i][0], two_dimention[i][1], two_dimention[i][2], two_dimention[i][3],
					two_dimention[i][4], two_dimention[i][5], two_dimention[i][6], two_dimention[i][7],
					two_dimention[i][8], two_dimention[i][9]);
				cout << " I: " << i << endl;
			}
		}
		//add 2
		if (count == 180 || count == 300 || count == 480 || count == 650)
		{
			if (Digits[4] + 2 < 10)
			{
				Digits[4] += 2;
			}
			else
			{
				Digits[4] += 2;
				Digits[4] -= 10;
			}
		}
	}
	//check for repeated
}


NumberGenerator::~NumberGenerator()
{
}
