#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("@brboywolf"), grade(42)
{
    std::cout << "Default Constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    std::cout << "Set Constructor called" << std::endl;
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->grade = grade;
    }
    catch (GradeTooHighException& high)
    {
        std::cerr << high.what() << std::endl;
        this->grade = 1;
    }
    catch (GradeTooLowException& low)
    {
        std::cerr << low.what() << std::endl;
        this->grade = 150;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& src): name("Copy")
{
    std::cout << "Copy Constructor called" << std::endl;
    this->grade = src.grade;
    return ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int    Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

std::string    Bureaucrat::getName(void) const
{
    return (this->name);
}

void    Bureaucrat::plusGrade()
{
    try
    {
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->grade--;
    }
    catch (GradeTooHighException& high)
    {
        std::cerr << high.what() << std::endl;
    }
}

void    Bureaucrat::minusGrade()
{
    try
    {
        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->grade++;
    }
    catch (GradeTooLowException& low)
    {
        std::cerr << low.what() << std::endl;
    }
}

void    Bureaucrat::signForm(Form &Form)
{
    try
    {
        Form.beSigned(*this);
    }
    catch(GradeTooLowException& low)
    {
        std::cout << this->name << " couldn't sign " << Form.getName() << " because Grade is too low" << std::endl;
        return ;
    }
}

const	char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too High exception");
}

const	char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low exception");
}

const	char *Bureaucrat::NotExecutable::what(void) const throw()
{
    return ("Form is not executable");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& rhs)
{
    this->grade = rhs.grade;
    return (*this);
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const& src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (out);
}

void Bureaucrat::executeForm(Form const &form) {
    try
    {
        form.execute(*this);
        std::cout << getName() << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << getName() << " cannot execute " << form.getName()
            << " " <<  ex.what() << std::endl;
    }
}
