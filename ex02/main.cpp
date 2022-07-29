#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
		Bureaucrat bart( "Hommer simpson" , 13);
		Bureaucrat lisa( "Marge simpson" , 6);
		std::cout << bart;
		std::cout << "\n";

		Form* one = new ShrubberyCreationForm("Barney");
		Form* two = new RobotomyRequestForm("Krusty");
		Form* three = new PresidentialPardonForm("Moe");

	try
	{
		std::cout << *one << std::endl;
		bart.signForm(*one);
		bart.executeForm(*one);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << *two << std::endl;
		bart.signForm(*two);
		bart.executeForm(*two);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


		try
	{
		std::cout << *three << std::endl;
		bart.signForm(*three);
		bart.executeForm(*three);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout <<  "\n TESTE INCREMENT \n"  << std::endl;

	try
	{
		lisa.plusGrade();

		std::cout << *one << std::endl;
		lisa.signForm(*one);
		lisa.executeForm(*one);
		std::cout << "\n";
		std::cout << "\n";

		std::cout << *two << std::endl;
		lisa.signForm(*two);
		lisa.executeForm(*two);
		std::cout << "\n";
		std::cout << "\n";

		std::cout << *three << std::endl;
		lisa.signForm(*three);
		lisa.executeForm(*three);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete one;
	delete two;
	delete three;

    return (0);
}
