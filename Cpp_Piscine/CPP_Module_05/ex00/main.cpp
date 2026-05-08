#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat br("John", 4);
	std::cout << br;
	try{
		while(1)
			br.incrementGrade();
			//br.decrementGrade();
	}
	catch (std::exception &a)
	{
		std::cout << a.what();
	}
	return 0;
}