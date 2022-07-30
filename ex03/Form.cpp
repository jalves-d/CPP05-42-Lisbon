#include "Form.hpp"

Form::Form(): name("42Lisboa"), issigned(false), minsigned(50), minexec(40)
{
    std::cout << "Default Form Constructor called" << std::endl;
    return;
}

Form::Form(std::string name, int minSigned, int minExec)
: name(name), issigned(false), minsigned(minSigned), minexec(minExec)
{
    std::cout << "Set Form Constructor called" << std::endl;
    try
    {
        if (minSigned < 1 || minExec < 1)
            throw Form::GradeTooHighException();
        else if (minSigned > 150 || minExec > 150)
            throw Form::GradeTooLowException();
    }
    catch (GradeTooHighException &high)
    {
        std::cerr << high.what() << std::endl;
    }
    catch (GradeTooLowException &low)
    {
        std::cerr << low.what() << std::endl;
    }
}

Form::Form(Form const &src) : name("Copy"), minexec(50), minsigned(80)
{
    std::cout << "Copy Form Constructor called" << std::endl;
    this->issigned = src.issigned;
    return ;
}

Form::~Form()
{
    std::cout << "Destructor Form called" << std::endl;
    return;
}

std::string Form::getName(void) const
{
    return (this->name);
}

int    Form::getMinSigned(void) const
{
    return (this->minsigned);
}

int    Form::getMinExec(void) const
{
    return (this->minexec);
}

bool   Form::isSigned(void) const
{
    return (this->issigned);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too High exception !");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low exception !");
}

const char *Form::FormUnsigned::what(void) const throw()
{
    return ("Form is not signed !");
}

void Form::beSigned(Bureaucrat const& src)
{
    try
    {
        if (src.getGrade() <= this->minsigned && this->issigned == true)
            std::cout << "The form is already signed." << std::endl;
        else if (src.getGrade() <= this->minsigned)
        {
            std::cout << "The form is now signed." << std::endl;
            this->issigned = true;
        }
        else
            throw Bureaucrat::GradeTooLowException();
    }
    catch (GradeTooLowException& low)
    {
        std::cerr << low.what() << std::endl;
    }

}

void Form::isExecutable(Bureaucrat const& executor) const
{
    if (this->issigned == false)
    {
        throw Form::FormUnsigned();
    }
    else if (executor.getGrade() > this->minexec)
        throw Form::GradeTooLowException();
}

void Form::isExecutableBureaucrat(Bureaucrat const &executor) const
{
    if (this->issigned == false)
    {
        throw Bureaucrat::NotExecutable();
    }
    else if (executor.getGrade() > this->minexec)
        throw Bureaucrat::NotExecutable();
}

Form &Form::operator=(Form const &rhs)
{
    this->issigned = rhs.issigned;
    return (*this);
}

std::ostream& operator<<(std::ostream &out, Form const& src)
{
	std::string issigned = src.isSigned() ? "Yes" : "No";
    out << src.getName() << ":\nIs signed ? " << issigned << std::endl \
        << "Minimun grade to sign: " << src.getMinSigned() << std::endl \
        << "Minimum grade to execute: "<< src.getMinExec() << std::endl;
    return (out);
}
