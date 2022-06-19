#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
	    std::string const	name;
	    int					grade;
	public:
	    Bureaucrat();
		Bureaucrat(std::string name, int grade);
	    Bureaucrat(Bureaucrat const& src);
	    ~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		plusGrade();
		void		minusGrade();
		void		signForm(Form& Form);

	    Bureaucrat & operator=(Bureaucrat const& rhs);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const	char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const	char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream & out, Bureaucrat const& src);

#endif
