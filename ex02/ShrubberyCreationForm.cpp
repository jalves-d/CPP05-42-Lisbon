#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery creation", 145, 137)
{
    target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : Form("Shrubbery creation", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy)
    : Form(copy), target(copy.target)
{
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
    Form::operator=(copy);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {  }

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
   	if (this->getMinExec() < executor.getGrade())
		throw GradeTooLowException();
    std::ofstream file;
    file.open((_target + "_shrubbery").c_str());
    std::cout << "João" << " the tree is ready." << std::endl;

    file <<"        _#_          " << std::endl
    <<"       // \\)         " << std::endl
    <<"      // @ \\)        " << std::endl
    <<"     //     \\)       " << std::endl
    <<"    //  / \\  \\)      " << std::endl
    <<"   // o     O \\)     " << std::endl
    <<"  //___________\\)    " << std::endl
    <<"        |=|          " << std::endl
    <<"        |=|          " << std::endl
    <<"        |=|          " << std::endl
    <<"   ¨¨¨¨¨¨¨¨¨¨¨¨¨     " << std::endl;
}
