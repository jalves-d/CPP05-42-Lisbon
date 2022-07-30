#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private :
		typedef Form* (Intern::*action)(const std::string &target);
    public :
        Intern(void);
        Intern(Intern const& copy);
        Intern& operator=(Intern const& copy);
        ~Intern(void);

        Form* createShrubberyCreationForm(const std::string &target);
	    Form* createRobotomyRequestForm(const std::string &target);
	    Form* createPresidentialPardonForm(const std::string &target);
        Form *makeForm(std::string name, std::string target); 
};

#endif