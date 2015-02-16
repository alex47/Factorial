#include "Factorial_calc.h"

#include <iostream>

using namespace std;

bool isNumber(string num)
{
	for (int i = 0; i < num.length(); i++)
	{
		if (!isdigit(num[i]) || num[0] == '0')
		{			
			return false;
		}
	}

	return true;
}

//Gets number from input
int getNumber()
{
	string strNum;

	cout << "Number: ";
	cin >> strNum;

	if (!isNumber(strNum))
	{
		cout << endl << "------------------------------------" << endl << "          INVALID NUMBER" << endl << "------------------------------------" << endl << endl;
		return -1;
	}	

	return atoi(strNum.c_str());
}

int main(int argc, char *argv[])
{
	int num;
	Factorial_calc calc;

	if (argc == 1)
	{
		do
		{
			num = getNumber();

			if (num == -1)
			{
				continue;
			}

			cout << "Factorial of " << num << " is " << calc(num) << endl << endl;
		} while (true);
	}

	if (argc == 2)
	{
		if (!isNumber(argv[1]))
		{
			cout << endl << "------------------------------------" << endl << "          INVALID NUMBER" << endl << "------------------------------------" << endl << endl;
			return -1;
		}

		num = atoi(argv[1]);
		cout << "Factorial of " << num << " is " << calc(num) << endl << endl;
	}

	else
	{
		cout << "Too many arguments" << endl << endl;
	}
}
