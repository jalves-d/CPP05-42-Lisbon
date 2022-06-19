#include "Bureaucrat.hpp"

int main()
{
		Bureaucrat joao("João", 1);
		Bureaucrat otavio("Otavio", 43);
		Bureaucrat eduardo("Eduardo", 150);

		std::cout << joao << std::endl;
		std::cout << otavio << std::endl;
		std::cout << eduardo << std::endl;

		joao.plusGrade();
		otavio.plusGrade();
		eduardo.minusGrade();

		std::cout << otavio << std::endl;
}
