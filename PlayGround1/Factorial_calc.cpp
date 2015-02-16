#include "Factorial_calc.h"


//PUBLIC
Factorial_calc::Factorial_calc()
{
	
}


Factorial_calc::~Factorial_calc()
{

}


string Factorial_calc::operator()(int num)
{
	if (num == 1)
	{
		return "1";
	}

	//return multiply(to_string(num), Factorial_calc::operator()(num - 1));
	return multiply(Factorial_calc::operator()(num - 1), to_string(num));
}


//PRIVATE
int Factorial_calc::charToInt(char c)
{
	return c - '0';
}


int Factorial_calc::lengthOfMultipledNumber(vector<string> numbers)
{
	if (numbers.size() == 1)
	{
		return numbers[0].length();
	}

	int numberLength = numbers[numbers.size() - 1].length();

	for (int i = numbers.size() - 2; i >= 0; i--)
	{
		numberLength += numbers[i].length() - numbers[i + 1].length() + 1;
	}

	return numberLength;
}


vector<string> Factorial_calc::fillWithNulls(vector<string> numbers)
{
	int numLength = lengthOfMultipledNumber(numbers);

	nullFilling.clear();

	for (int i = 0; i < numbers.size(); i++)
	{
		nullFilling.push_back(
			async([](string number, int num, int size, int length)
			{
				number.append(size - num - 1, '0');

				while (number.length() < length)
				{
					number.insert(0, 1, '0');
				}

				return number;
			}, 
			numbers[i], i, numbers.size(), numLength));
	}

	for (int i = 0; i < nullFilling.size(); i++)
	{
		numbers[i] = nullFilling[i].get();
	}

	return numbers;
}


vector<string> Factorial_calc::calculateNums(const string num1, const string num2)
{
	vector<string> numsToAdd;
	vector<string> tempNums;
	string tempNum;
	string numToStore;
	int rest;

	for (int num2Index = 0; num2Index < num2.size(); num2Index++)
	{
		tempNums.clear();
		tempNum.clear();
		rest = 0;

		for (int num1Index = num1.length() - 1; num1Index >= 0; num1Index--)
		{
			tempNums.push_back(to_string(charToInt(num2[num2Index]) * charToInt(num1[num1Index])));
		}

		for (int i = 0; i < tempNums.size() - 1; i++)
		{
			numToStore = to_string(rest + atoi(tempNums[i].c_str()));
			rest = (numToStore.length() > 1) ? charToInt(numToStore[0]) : 0;
			tempNum.insert(0, 1, numToStore[numToStore.length() - 1]);
		}

		numToStore = to_string(rest + stoi(tempNums[tempNums.size() - 1], nullptr, 10));
		tempNum.insert(0, numToStore);

		numsToAdd.push_back(tempNum);
	}

	return numsToAdd;
}


pair<string, int> Factorial_calc::addNumbers(vector<char> numbers, int rest)
{
	int sum = 0;
	string sNum;
	pair<string, int> tempPair;

	for (int i = 0; i < numbers.size(); i++)
	{
		sum += charToInt(numbers[i]);
	}

	sum += rest;

	sNum = to_string(sum);

	tempPair.first = sNum.back();
	sNum.pop_back();

	tempPair.second = atoi(sNum.c_str());

	return tempPair;
}


string Factorial_calc::multiply(const string num1, const string num2)
{
	vector<string> numsToAdd = fillWithNulls(calculateNums(num1, num2));
	vector<char> nums;
	pair<string, int> tempPair;
	string finalNum;
	int rest = 0;

	for (int i = numsToAdd[0].length() - 1; i > 0; i--)
	{
		nums.clear();

		for (int j = 0; j < numsToAdd.size(); j++)
		{
			nums.push_back(numsToAdd[j][i]);
		}

		tempPair = addNumbers(nums, rest);
		rest = tempPair.second;

		finalNum.insert(0, tempPair.first);
	}

	nums.clear();

	for (int j = 0; j < numsToAdd.size(); j++)
	{
		nums.push_back(numsToAdd[j][0]);
	}

	tempPair = addNumbers(nums, rest);

	finalNum.insert(0, to_string(atoi(tempPair.first.c_str()) + tempPair.second * 10));

	while (finalNum.front() == '0')
	{
		finalNum.erase(0, 1);
	}

	return finalNum;
}

