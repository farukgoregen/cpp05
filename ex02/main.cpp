#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
    std::srand(std::time(0));

    std::cout << "--- Test 1: ShrubberyCreationForm ---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 136);
        ShrubberyCreationForm shrubbery("home");
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 2: RobotomyRequestForm ---" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robotomy("Bender");
        alice.signForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 3: PresidentialPardonForm ---" << std::endl;
    try
    {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Faruk");
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 4: Execute without signing ---" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robotomy("Target");
        alice.executeForm(robotomy);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}