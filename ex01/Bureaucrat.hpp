#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat{
	private:
		std::string const name;
		int grade;

	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat & operator=(const Bureaucrat &cpy);
		std::string &getName(void) const;
		int getGrade(void) const;
		void Increment(void);
		void Decrement(void);
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cpy);

#endif
