#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <fstream>
# include <string>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& copy);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& copy);
		virtual ~ShrubberyCreationForm(void);

		virtual void execute(Bureaucrat const& executor) const;
	private:

		std::string target;
};

#endif
