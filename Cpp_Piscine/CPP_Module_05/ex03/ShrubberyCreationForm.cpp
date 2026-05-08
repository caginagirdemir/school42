#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;

	*this = src;
}

// Deconstructors
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

// Public Methods
void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw (Form::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

			outfile << "                                                         .\n";
            outfile << "                                              .         ;\n";
            outfile << "                 .              .              ;%     ;;\n";
            outfile << "                   ,           ,                :;%  %;\n";
            outfile << "                    :         ;                   :;%;'     .,\n";
            outfile << "           ,.        %;     %;            ;        %;'    ,;\n";
            outfile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
            outfile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
            outfile << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
            outfile << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
            outfile << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
            outfile << "                    `:%;.  :;bd%;          %;@%;'\n";
            outfile << "                      `@%:.  :;%.         ;@@%;'\n";
            outfile << "                        `@%.  `;@%.      ;@@%;\n";
            outfile << "                          `@%%. `@%%    ;@@%;\n";
            outfile << "                            ;@%. :@%%  %@@%;\n";
            outfile << "                              %@bd%%%bd%%:;\n";
            outfile << "                                #@%%%%%:;;\n";
            outfile << "                               %@@%%%::;\n";
            outfile << "                                %@@@%(o);  . '\n";
            outfile << "                                %@@@o%;:(.,'\n";
            outfile << "                            `.. %@@@o%::;\n";
            outfile << "                               `)@@@o%::;\n";
            outfile << "                                %@@(o)::;\n";
            outfile << "                               .%@@@@%::;\n";
            outfile << "                               ;%@@@@%::;.\n";
            outfile << "                              ;%@@@@%%:;;;.\n";
            outfile << "                          ...;%@@@@@%%:;;;;,..\n";
		outfile.close();
	}
}

// Getter
std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}

