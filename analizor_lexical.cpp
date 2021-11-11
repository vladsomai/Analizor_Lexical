#include "lib.h"

/*
* return true if name is valid
* Nume spatiu prenume
* 
* Nume: litera_mare litera_mica+
* Prenume: litera_mare litera_mica+ ((minus litera_mare litera_mica+_ | epsilon)
*/
bool LastNameIsValid(const std::string& input)
{
	size_t inputLength = input.length();
	for (uint32_t i = 0; i <= inputLength; i++)
	{
		if (i == inputLength)
			return true;

		if (i == 0)
		{
			if (isupper(input[i]))
				continue;
			else
				break;
		}

		if (isalpha(input[i]) && islower(input[i]))
			continue;
		else
			break;
	}

	return false;
}

bool FirstNameIsValid(const std::string& input)
{
	size_t inputLength = input.length();
	bool minusEncountered = false;

	for (uint32_t i = 0; i <= inputLength; i++)
	{
		if (i == inputLength)
			return true;

		if (i == 0)
		{
			if (isupper(input[i]))
				continue;
			else
				break;
		}

		if (input[i] == '-')
			if (FirstNameIsValid(input.substr(i + 1, inputLength - i)))
				return true;

		if (isalpha(input[i]) && islower(input[i]))
			continue;
		else
			break;
	}

	return false;
}

std::vector<std::string> nameSplitter(const std::string& fullName)
{
	std::vector<std::string> name;
	size_t inputLength = fullName.length();
	for (uint32_t i = 0; i != inputLength; i++)
	{
		if (fullName[i] == ' ')
		{
			name.push_back(fullName.substr(0, i));
			name.push_back(fullName.substr(i+1, inputLength - i));
			break;
		}
	}
	return name;
}