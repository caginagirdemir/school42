#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("John", 5);
	Form	test("test1", 150, 150);
	std::cout << test;
	a.signForm(test);
	std::cout << test;
	return (0);
}
