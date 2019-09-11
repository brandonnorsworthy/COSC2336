/*
Copyright by Brandon Norsworthy
September 10, 2019
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

int vowelFinder(char* cstring);

int main() {
	std::string str;
	std::cin >> str;
	char* cstr = new char[str.length() + 1];
	strcpy_s(cstr, str.length() + 1, str.c_str());

	//make all letters to upper so i can type less
	for (int i = 0; i < strlen(cstr); i++)
	{
		cstr[i] = toupper(cstr[i]);
		std::cout << cstr[i] << ", ";
	}

	std::cout << std::endl;
	std::cout << "Vowel amount: " << vowelFinder(cstr);
}

//Recursively adds up vowel amount in given cstring
int vowelFinder(char* cstring)
{
	if (cstring[0] == NULL)
	{
		std::cout << "cstring == null" << std::endl;
		return 0;
	}
	else
	{
		//working if statement
		if (cstring[0] == 'A' || cstring[0] == 'E' || cstring[0] == 'I' || cstring[0] == 'O' || cstring[0] == 'U')
		{
			//TODO memmove working unknown
			std::cout << "cstring[0] = " << cstring[0] << std::endl;
			memmove(&cstring[0], &cstring[1], strlen(cstring));
			return 1 + vowelFinder(cstring);
		}
		else
		{
			std::cout << "cstring[0] = " << cstring[0] << std::endl;
			memmove(&cstring[0], &cstring[1], strlen(cstring));
			return 0 + vowelFinder(cstring);
		}
	}
}