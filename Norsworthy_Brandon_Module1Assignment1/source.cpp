/*
Copyright by Brandon Norsworthy
September 10, 2019
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

int vowels(char* cstring);

int main() {
	std::ifstream iFile("input.txt"); //input file
	std::ofstream oFile("output.txt"); //output file
	std::string str; //string to copy text into until its converted to a cstring
	int vowelAmount = 0; //stores amount of vowels while going through the lines

	while (std::getline(iFile, str))
	{
		//Copies the input string over to a cstring to send off to vowel counter
		char* cstr = new char[str.length() + 1];
		strcpy_s(cstr, str.length() + 1, str.c_str());

		//loops through to make all alphabetical characters uppercase so if statements are reduced
		char c;
		for (int i = 0; i < strlen(cstr); i++)
		{
			c = cstr[i];
			if (isalpha(c))
			{
				if (!isspace(c))
				{
					cstr[i] = toupper(cstr[i]);
				}
			}
		}
		vowelAmount += vowels(cstr);
	}
	iFile.close();

	char vowelAmountC[10];
	_itoa_s(vowelAmount, vowelAmountC, 10);
	if (oFile)
	{
		oFile << vowelAmountC;
	}
	oFile.close();

	return 0;
}

//Recursively adds up vowel amount in given cstring
int vowels(char* cstring)
{
	//if cstring is empty stop recursion
	if (cstring[0] == NULL)
	{
		return 0;
	}
	else
	{
		//test if current char at front of cstring is a vowel if it is add 1 to vowel count and call function again
		if (cstring[0] == 'A' || cstring[0] == 'E' || cstring[0] == 'I' || cstring[0] == 'O' || cstring[0] == 'U')
		{
			memmove(&cstring[0], &cstring[1], strlen(cstring)); //remove front character after it is tested
			return 1 + vowels(cstring);
		}
		else
		{
			memmove(&cstring[0], &cstring[1], strlen(cstring)); //remove front character after it is tested
			return 0 + vowels(cstring);
		}
	}
}