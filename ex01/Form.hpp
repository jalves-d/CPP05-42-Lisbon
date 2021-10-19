#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form{
	private:
		std::string const name;
		bool signed;
		int const gradesig;
		int const gradeexec;

	public:
		Form(void);
		~Form(void);
		Form(const Form &cpy);
		Form & operator=(const Form &cpy);
		std::string &getName(void) const;
		bool getSigned(void);
		int getGradeSig(void) const;
		int getGradeExec(void) const;
		void beSigned(Bureaucrat const & bureaucrat);
}

std::ostream &operator<<(std::ostream &out, const Form &cpy);

#endif
