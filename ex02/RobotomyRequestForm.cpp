#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy request", 72, 45)
{
    target = "none";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : Form("Robotomy request", 72, 45)
{
    target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy)
    : Form(copy), target(copy.target)
{
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
    Form::operator=(copy);
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {  }

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (getMinExec() < executor.getGrade())
        throw GradeTooLowException();
    else
        std::cout << "FRIIIIII " << target << " has been robotomized successfully 50\% of the time" << std::endl;
}
