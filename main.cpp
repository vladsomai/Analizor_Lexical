#include "lib.h"


extern bool LastNameIsValid(const std::string& input);
extern bool FirstNameIsValid(const std::string& input);
extern std::vector<std::string> nameSplitter(const std::string& fullName);
int main()
{
	std::vector<std::string> nameVect = nameSplitter("Somai Vlad-Gabriel");
	std::string LastName;
	std::string FirstName;

	try 
	{
		LastName = nameVect.at(0);
		FirstName = nameVect.at(1);
	}
	catch (const std::out_of_range& err)
	{
		std::cout << "The provided full name is invalid" << std::endl;
		std::cout << err.what() << std::endl;
		return -1;
	}

	if (LastNameIsValid(LastName) && FirstNameIsValid(FirstName))
		std::cout << "Nume is valid" << std::endl;
	else
		std::cout << "Nume is invalid" << std::endl;

}