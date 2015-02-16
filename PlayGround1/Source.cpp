#include "Factorial_calc.h"

#include <iostream>

using namespace std;

//Gets number from input
int getNumber()
{
	string strNum;

	cout << "Number: ";
	cin >> strNum;

	for (int i = 0; i < strNum.length(); i++)
	{
		if (!isdigit(strNum[i]) || strNum[0] == '0')
		{
			cout << endl << "------------------------------------" << endl << "          INVALID NUMBER" << endl << "------------------------------------" << endl << endl;
			return -1;
		}
	}

	return atoi(strNum.c_str());
}

void main()
{
	int num;
	Factorial_calc calc;

	while (true)
	{
		num = getNumber();

		if (num == -1)
		{
			continue;
		}

		cout << "Factorial of " << num << " is " << calc(num) << endl << endl;
	}
}
