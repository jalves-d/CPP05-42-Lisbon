#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	this->name = name;
	this->grade = grade;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
    if (this == &cpy)
    {
        return (*this);
    }
    name = cpy.name;
	grade = cpy.grade;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
    return(*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cpy)
{
    out << cpy.getName() <<", bureaucrat grade" << cpy.getGrade();
	return (out);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
    if (this != &cpy)
	{
		grade = cpy.grade;
        name = cpy.name;
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
}

std::string	const &Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::Increment(void)
{
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::Decrement(void)
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}
