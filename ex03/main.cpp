#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {

	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("Intern doenst create", "Bender");
}