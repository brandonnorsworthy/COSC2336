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
	//input file

	//test input string to verify vowelFinder works
	std::string str;
	std::getline(std::cin, str); //make sure to grab incase multiple words/spaces present

	//copies over str int a cstring to send off to vowelFinder
	char* cstr = new char[str.length() + 1];
	strcpy_s(cstr, str.length() + 1, str.c_str());

	//loops through cstr to test for spaces and convert to uppercase
	char c;
	for (int i = 0; i < strlen(cstr); i++)
	{
		c = cstr[i];
		if (!isspace(c))
		{
			cstr[i] = toupper(cstr[i]);
			//std::cout<< cstr[i] << ", "; //prints out characters to make sure they are uppercase
		}
	}

	//call vowelFinder after prepping has been completed
	std::cout << std::endl;
	std::cout << "Vowel amount: " << vowels(cstr);
}

//Recursively adds up vowel amount in given cstring
int vowels(char* cstring)
{
	//if cstring is empty stop recursion
	if (cstring[0] == NULL)
	{
		//std::cout << "cstring == null" << std::endl;
		return 0;
	}
	else
	{
		//test if current char at front of cstring is a vowel if it is add 1 to vowel count and call function again
		if (cstring[0] == 'A' || cstring[0] == 'E' || cstring[0] == 'I' || cstring[0] == 'O' || cstring[0] == 'U')
		{
			//std::cout << "cstring[0] = " << cstring[0] << std::endl; //prints out front character to make sure its a vowel
			memmove(&cstring[0], &cstring[1], strlen(cstring)); //remove front character after it is tested
			return 1 + vowels(cstring);
		}
		else
		{
			//std::cout << "cstring[0] = " << cstring[0] << std::endl; //prints out front character to make sure its not a vowel
			memmove(&cstring[0], &cstring[1], strlen(cstring)); //remove front character after it is tested
			return 0 + vowels(cstring);
		}
	}
}