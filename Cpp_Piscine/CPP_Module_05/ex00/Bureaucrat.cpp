#include "Bureaucrat.hpp"


// Constructors
Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}


Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
		this->setGrade(grade);
}

// Deconstructors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

// Public Methods
void	Bureaucrat::incrementGrade(void)
{
		std::cout << "[INCREMENT]" << this->getName() << " , " << this->getGrade() << std::endl;
		this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "[DECREMENT]" << this->getName() << " , " << this->getGrade() << std::endl;
	this->setGrade(this->_grade + 1);
}

const std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}
size_t	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low Exception!");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too Low Exception!");
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
	return (o);
}
