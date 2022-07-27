#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool issigned;
        int const minsigned;
        int const minexec;

    public:
        Form();
        Form(std::string name, int minSigned, int minExec);
        Form(Form const& src);
        ~Form();

        std::string	getName() const;
        int         getMinSigned(void) const;
        int         getMinExec(void) const;
        bool        isSigned(void) const;
        void        beSigned(Bureaucrat const& src);
		void        isExecutable(Bureaucrat const& executor) const;
        void        isExecutableBureaucrat(Bureaucrat const &executor) const;
        virtual void execute(Bureaucrat const &executor) const = 0;
        Form & operator=(Form const& rhs);

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
	class FormUnsigned : public std::exception
    {
    	public:
        	virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif
