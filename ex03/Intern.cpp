#include "Intern.hpp"

Intern::Intern(void) {  }

Intern::Intern(Intern const& copy)
{
    *this = copy;
}

Form* Intern::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

Intern::~Intern() { }

Form *Intern::makeForm(std::string name, std::string target)
{
	const std::string str[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	action actions[] = { &Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (name == str[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*actions[i])(target);
		}
	}
	std::cout << "Intern makeForm invalid because nothing was found!" << std::endl;
	return NULL;
}