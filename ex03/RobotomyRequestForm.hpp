#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <string>
# include <iostream>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& copy);
		~RobotomyRequestForm(void);

		virtual void execute(Bureaucrat const& executor) const;
	private:
		std::string target;
};

#endif
