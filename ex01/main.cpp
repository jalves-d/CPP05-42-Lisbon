#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat joao("João", 1);
	Bureaucrat otavio("Otavio", 43);
	Bureaucrat john(joao);
    Bureaucrat wolf;
    wolf = john;

    Form    form1("Proclamação da Independência", 50, 40);
    Form    form2;
    Form    form3(form2);

    form2 = form1;

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << std::endl << joao << std::endl;
    std::cout << otavio << std::endl;
    std::cout << john << std::endl << std::endl;
    otavio.minusGrade();
    std::cout << otavio << std::endl;
    otavio.plusGrade();
    std::cout << otavio << std::endl;
    otavio.plusGrade();
    std::cout << otavio << std::endl;

    joao.minusGrade();
    std::cout << joao << std::endl;
    joao.minusGrade();
    std::cout << joao << std::endl;
    joao.plusGrade();
    std::cout << joao << std::endl;

    otavio.signForm(form1);
    otavio.signForm(form1);
    joao.signForm(form2);
    std::cout << joao << std::endl;
    joao.plusGrade();
    std::cout << joao << std::endl;
    joao.plusGrade();
    std::cout << joao << std::endl;

    std::cout << form2 << std::endl;
    joao.signForm(form2);
    joao.signForm(form2);

    std::cout << wolf << std::endl;
    std::cout << form2 << std::endl;

}
