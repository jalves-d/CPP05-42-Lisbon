
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential pardon", 25, 5)
{
    target = "none";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
    Form("Presidential pardon", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy)
    : Form(copy), target(copy.target)
{
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
    Form::operator=(copy);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {  }

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (getMinExec() < executor.getGrade())
        throw GradeTooLowException();
    else
        std::cout << "" << target << " has been pardoned by Zafod Beeblebrox." <<std::endl;
}
