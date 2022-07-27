#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <iostream>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const& target);
		PresidentialPardonForm(PresidentialPardonForm const& copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& copy);
		~PresidentialPardonForm(void);

		virtual void execute(Bureaucrat const & executor) const;
	private:
		std::string target;
};

#endif
