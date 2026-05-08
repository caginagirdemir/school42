#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat br("Tester", 130);
    std::cout << br << std::endl;
    ShrubberyCreationForm sh_frm("test");
    RobotomyRequestForm ro_frm;
    try{
        br.signForm(sh_frm);
        sh_frm.execute(br);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
	return (0);
}
