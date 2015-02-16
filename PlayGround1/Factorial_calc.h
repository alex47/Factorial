#pragma once

#include <vector>
#include <string>
#include <thread>
#include <cctype>

using namespace std;

class Factorial_calc
{
public:
	Factorial_calc();
	~Factorial_calc();

	//Overloads the () operator
	string operator()(int num);

private:
	//Converts a char to int
	int charToInt(char c);

	//Calculates the length of the final number
	int lengthOfMultipledNumber(vector<string> numbers);

	//Fills the front and back of the numbers with 0 characters
	//to make calculations easier
	vector<string> fillWithNulls(vector<string> numbers);

	//Calculates the numbers that need to be summed
	vector<string> calculateNums(const string num1, const string num2);

	//Summes single digit numbers
	pair<string, int> addNumbers(vector<char> numbers, int rest);

	//Multiplies two numbers
	string multiply(const string num1, const string num2);
};

